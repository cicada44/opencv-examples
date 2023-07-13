// -----------------------------------------------------------------------------
//
// Example for HPF in C++.
//
// -----------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img = cv::imread("../../img.jpg", 0), k3, k5, blurred, g_hpf;

    cv::Mat kernel_3x3 = (cv::Mat_<int>(3, 3) << -1, -1, -1, -1, 8, -1, -1, -1, -1);
    cv::Mat kernel_5x5 = (cv::Mat_<int>(5, 5) << -1, -1, -1, -1, -1, -1, 1, 2, 1, -1, -1, 2, 4, 2, -1, -1, 1, 2, 1, -1,
                          -1, -1, -1, -1, -1);

    cv::filter2D(img, k3, -1, kernel_3x3);
    cv::filter2D(img, k5, -1, kernel_5x5);

    cv::GaussianBlur(img, blurred, cv::Size(13, 13), 0);

    g_hpf = blurred - img;

    cv::imshow("3x3", k3);
    cv::imshow("5x5", k5);
    cv::imshow("blurred", blurred);
    cv::imshow("g_hpf", g_hpf);

    cv::waitKey();
    cv::destroyAllWindows();
}
