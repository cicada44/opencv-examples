// -----------------------------------------------------------------------------
//
// Example for Gaussian bluring
//
// -----------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img = cv::imread("../../img.jpg", 0), blured_3, blured_5, blured_7;

    // Bluring with different keys
    cv::GaussianBlur(img, blured_3, cv::Size(3, 3), 0);
    cv::GaussianBlur(img, blured_5, cv::Size(5, 5), 0);
    cv::GaussianBlur(img, blured_7, cv::Size(7, 7), 0);

    cv::imshow("blured_3", blured_3);
    cv::imshow("blured_5", blured_5);
    cv::imshow("blured_7", blured_7);

    cv::waitKey();
    cv::destroyAllWindows();
}
