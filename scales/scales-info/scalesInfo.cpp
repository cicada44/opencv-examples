//-----------------------------------------------------------------------------
//
// Example for info of cv::Mat type in C++ with OpenCV.
//
//-----------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

int main() {
    cv::Mat image = cv::imread("image.png");

    if (image.empty()) exit(-1);

    std::cout << "size: " << image.size() << '\n';
    std::cout << "channels: " << image.channels() << '\n';
    std::cout << "depth: " << image.depth() << '\n';
    std::cout << "rows: " << image.rows << '\n';
    std::cout << "cols: " << image.cols << '\n';
    std::cout << "empty: " << image.empty() << '\n';
    std::cout << "type: " << image.type() << '\n';
    std::cout << "total: " << image.total() << '\n';
    std::cout << "elemSize: " << image.elemSize() << '\n';
    std::cout << "elemSize1: " << image.elemSize1() << '\n';
}
