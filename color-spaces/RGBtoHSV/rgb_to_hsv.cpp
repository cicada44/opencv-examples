//-----------------------------------------------------------------------------
//
// Example for translation image from RGB to HSV color space on C++ with OpenCV.
//
//-----------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

int main() {
    cv::Mat imageRGB = cv::imread("image.png");

    if (imageRGB.empty()) {
        std::cerr << "Error: Could not read the image file" << std::endl;
        return -1;
    }

    cv::Mat imageHSV;
    cv::cvtColor(imageRGB, imageHSV, cv::COLOR_RGB2HSV);

    cv::imwrite("imageHSV.png", imageHSV);
}
