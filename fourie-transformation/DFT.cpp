//-----------------------------------------------------------------------------
//
// Example for fourie transformation in C++ with OpenCV.
//
//-----------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

int main() {
    cv::Mat image = cv::imread("lena.jpg", cv::IMREAD_GRAYSCALE);

    /* Creating new image for DFT optimal size. */
    cv::Mat padded;
    int m = cv::getOptimalDFTSize(image.rows);
    int n = cv::getOptimalDFTSize(image.cols);

    cv::copyMakeBorder(image, padded, 0, m - image.rows, 0, n - image.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));

    cv::Mat planes[] = {cv::Mat_<float>(padded), cv::Mat::zeros(padded.size(), CV_32F)};
    cv::Mat complexI;
    cv::merge(planes, 2, complexI);

    /* This way the result will fit the src matrix. */
    cv::dft(complexI, complexI);

    /* Compute the magnitude and switch to logarithmic scale => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2)). */
    cv::split(complexI, planes);
    cv::magnitude(planes[0], planes[1], planes[0]);
    cv::Mat magI = planes[0];

    magI += cv::Scalar::all(1);
    cv::log(magI, magI);

    /* Crop the spectrum, if it has an odd number of rows or columns. */
    magI = magI(cv::Rect(0, 0, magI.cols & -2, magI.rows & -2));

    /* Rearrange the quadrants of Fourier image so that the origin is at the image center. */
    int cx = magI.cols / 2;
    int cy = magI.rows / 2;

    cv::Mat q0(magI, cv::Rect(0, 0, cx, cy));    // Top-Left - Create a ROI per quadrant.
    cv::Mat q1(magI, cv::Rect(cx, 0, cx, cy));   // Top-Right.
    cv::Mat q2(magI, cv::Rect(0, cy, cx, cy));   // Bottom-Left.
    cv::Mat q3(magI, cv::Rect(cx, cy, cx, cy));  // Bottom-Right.
    cv::Mat tmp;                                 // Swap quadrants (Top-Left with Bottom-Right).

    q0.copyTo(tmp);
    q3.copyTo(q0);

    tmp.copyTo(q3);

    /* Swap quadrant (Top-Right with Bottom-Left). */
    q1.copyTo(tmp);
    q2.copyTo(q1);

    tmp.copyTo(q2);

    normalize(magI, magI, 0, 1, cv::NORM_MINMAX); /* Transform the matrix with float values into a
                                                   viewable image form (float between values 0 and 1). */

    cv::imshow("spectrum magnitude", magI);

    cv::waitKey();
    cv::destroyAllWindows();
}
