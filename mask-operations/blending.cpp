//-----------------------------------------------------------------------------
//
// Example for images blending in C++.
//
//-----------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img1, img2, result;

    img1 = cv::imread("../img.jpg", cv::IMREAD_COLOR);
    img2 = cv::imread("../img.jpg", cv::IMREAD_COLOR);

    // Make sence for blending.
    cv::flip(img1, img2, 0);

    // Blend for 50%.
    cv::addWeighted(img1, 0.5, img2, 0.5, 0.0, result);

    cv::namedWindow("blending");
    cv::imshow("blending", result);

    cv::waitKey();
    cv::destroyAllWindows();
}
