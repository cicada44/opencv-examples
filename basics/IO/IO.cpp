//-----------------------------------------------------------------------------
//
// Example for images input/output in C++ with OpenCV.
//
//-----------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

int main() {
    /* Read image with standard colors. */
    cv::Mat img = cv::imread("../img.jpg");

    /* Read image with Gray colors. */
    cv::Mat imgGrayscale = cv::imread("../img.jpg", cv::IMREAD_GRAYSCALE);

    /* Save image. */
    cv::imwrite("img.jpg", img);

    /*  For byte-IO:
     *      cv::imdecode()
     *      cv::imencode()
     */
}
