//-----------------------------------------------------------------------------
//
// Example for contrast and brightness changing in C++.
//
//-----------------------------------------------------------------------------
//
// Hand-written version of cv::convertScaleAbs() function.
//
//------------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

int main() {
    float alpha = 2, beta = -50;
    cv::Mat src, img;

    src = cv::imread("../img.jpg");
    img = cv::imread("../img.jpg");

    // Change all cells for formula `A*pixel + B`.
    for (int i = 0; i != img.rows; ++i) {
        for (int j = 0; j != img.cols; ++j) {
            for (int c = 0; c != img.channels(); ++c) {
                uchar& cellRef = img.at<cv::Vec3b>(i, j)[c];
                cellRef = cv::saturate_cast<uchar>(cellRef * alpha + beta);
            }
        }
    }

    cv::namedWindow("new");
    cv::imshow("new", img);
    cv::namedWindow("src");
    cv::imshow("src", src);

    cv::waitKey();
    cv::destroyAllWindows();
}
