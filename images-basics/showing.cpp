//-----------------------------------------------------------------------------
//
// Example for showing image in C++.
//
//-----------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img;

    img = cv::imread("../img.jpg", cv::IMREAD_COLOR);

    // Create window with name "image".
    cv::namedWindow("image");

    // Show image into created window.
    cv::imshow("image", img);

    // Press any key to quit.
    cv::waitKey();
    cv::destroyAllWindows();
}
