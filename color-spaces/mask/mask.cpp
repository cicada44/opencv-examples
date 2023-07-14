//-----------------------------------------------------------------------------
//
// Example for highlight blue shades from RGB image on C++ with OpenCV.
//
//-----------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

#include <algorithm>
#include <vector>

int main() {
    cv::Mat imageRGB = cv::imread("image.png");
    cv::Mat blueRegions, imageBlue;

    if (imageRGB.empty()) exit(-1);

    cv::Scalar lowerBlue{15, 15, 0};
    cv::Scalar upperBlue{130, 170, 255};

    cv::inRange(imageRGB, lowerBlue, upperBlue, blueRegions);

    cv::bitwise_and(imageRGB, imageRGB, imageBlue, blueRegions);

    cv::imwrite("imageBlue.png", imageBlue);
}
