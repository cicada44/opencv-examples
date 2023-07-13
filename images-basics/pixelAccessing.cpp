//-----------------------------------------------------------------------------
//
// Example for pixel accessing in C++.
//
//-----------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

#include <iostream>

int main() {
    cv::Mat img = cv::imread("../img.jpg", cv::IMREAD_COLOR);

    // Access to (0, 0) coordinates pixel.
    cv::Scalar intensity1 = img.at<uchar>(0, 0);

    std::cout << "(0, 0) - " << intensity1 << '\n';

    // Another way.
    cv::Scalar intensity2 = img.at<uchar>(cv::Point(0, 0));

    std::cout << "(100, 50) - " << intensity2 << '\n';

    cv::Vec3b intensity3 = img.at<cv::Vec3b>(0, 0);

    std::cout << "\nB - " << static_cast<int>(intensity3.val[0]) << '\n';
    std::cout << "R - " << static_cast<int>(intensity3.val[1]) << '\n';
    std::cout << "G - " << static_cast<int>(intensity3.val[2]) << '\n';

    // And pixel changing.
    img.at<uchar>(0, 0) = 128;
}
