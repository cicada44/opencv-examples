//-----------------------------------------------------------------------------
//
// Example for memory management responsibility of cv::Mat in C++
//
//-----------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

int main() {
    cv::Mat A, C, D;

    A = cv::imread("../img.jpg");

    /* Copy constructor and copy assigment operator copies only header.
     * https://docs.opencv.org/4.x/d6/d6d/tutorial_mat_the_basic_image_container.html
     */
    cv::Mat B(A);
    C = A;

    /* To copy data itself, use this. */
    A.copyTo(D);
    D = A.clone();

    cv::imshow("A", A);
    cv::imshow("B", B);

    cv::waitKey();
    cv::destroyAllWindows();
}
