// -----------------------------------------------------------------------------
//
// Example for median bluring
//
// -----------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img = cv::imread("../../img.jpg", 0), blurred_3, blurred_5, blurred_7;

    // Median bluring applies only even numbers
    cv::medianBlur(img, blurred_3, 3);
    cv::medianBlur(img, blurred_5, 5);
    cv::medianBlur(img, blurred_7, 7);

    cv::imshow("img", img);
    cv::imshow("blurred_7", blurred_7);
    cv::imshow("blurred_5", blurred_5);
    cv::imshow("blurred_3", blurred_3);

    cv::waitKey();
    cv::destroyAllWindows();
}
