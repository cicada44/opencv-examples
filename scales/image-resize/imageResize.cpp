// -----------------------------------------------------------------------------
//
// Example for image resizing in C++ with OpenCV.
//
// -----------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat image = cv::imread("image.png");

    image.resize(image.rows / 2);

    cv::imwrite("imageResized.png", image);
}
