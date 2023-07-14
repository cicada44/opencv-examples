//-----------------------------------------------------------------------------
//
// Example for cv::Mat sharpening in C++ with OpenCV.
//
//-----------------------------------------------------------------------------
//
// Handwritten version of cv::filter2D function.
//
//------------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

#include <iostream>

int main() {
    cv::Mat inputImg, outputImg;

    inputImg = cv::imread("../img.jpg", cv::IMREAD_COLOR);

    cv::namedWindow("input");
    cv::namedWindow("output");

    outputImg.create(cv::Size(inputImg.size()), inputImg.type());

    /* Sharpening part. */
    const int nChannels = inputImg.channels();
    outputImg.create(inputImg.size(), inputImg.type());
    for (int j = 1; j < inputImg.rows - 1; ++j) {
        const uchar* previous = inputImg.ptr<uchar>(j - 1);
        const uchar* current = inputImg.ptr<uchar>(j);
        const uchar* next = inputImg.ptr<uchar>(j + 1);
        uchar* output = outputImg.ptr<uchar>(j);
        for (int i = nChannels; i < nChannels * (inputImg.cols - 1); ++i) {
            output[i] = cv::saturate_cast<uchar>(5 * current[i] - current[i - nChannels] - current[i + nChannels] -
                                                 previous[i] - next[i]);
        }
    }
    outputImg.row(0).setTo(cv::Scalar(0));
    outputImg.row(outputImg.rows - 1).setTo(cv::Scalar(0));
    outputImg.col(0).setTo(cv::Scalar(0));
    outputImg.col(outputImg.cols - 1).setTo(cv::Scalar(0));

    cv::imshow("input", inputImg);
    cv::imshow("output", outputImg);

    cv::waitKey();
    cv::destroyAllWindows();
}
