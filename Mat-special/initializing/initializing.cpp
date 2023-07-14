//-----------------------------------------------------------------------------
//
// Example for cv::Mat initializing in C++ with OpenCV.
//
//-----------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

#include <iostream>

int main() {
    cv::Mat A(2, 2, CV_8UC3, cv::Scalar(0, 0, 255));
    cv::Mat B, C, D, E, F, G, R;

    /* Cannot assign matrix values in this case. */
    B.create(3, 3, CV_8UC3);

    /* MatLab style. */
    C = cv::Mat::eye(cv::Size(4, 4), CV_64F);
    D = cv::Mat::zeros(cv::Size(2, 2), CV_32F);
    E = cv::Mat::ones(cv::Size(2, 2), CV_8UC1);

    /* For small matricies we have troubles... */
    F = (cv::Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    G = (cv::Mat_<double>({0, -1, 0, -1, 5, -1, 0, -1, 0})).reshape(3);

    /* Init Mat with random values. */
    R = cv::Mat::zeros(cv::Size(400, 400), CV_8UC3);
    cv::randu(R, cv::Scalar::all(0), cv::Scalar::all(255));

    std::cout << "\nA (common)\n" << A << '\n';
    std::cout << "\nB (NumPy)\n" << cv::format(B, cv::Formatter::FMT_NUMPY) << '\n';
    std::cout << "\nC (MatLab)\n" << cv::format(C, cv::Formatter::FMT_C) << '\n';
    std::cout << "\nD (CSV)\n" << cv::format(D, cv::Formatter::FMT_CSV) << '\n';
    std::cout << "\nE (C)\n" << cv::format(E, cv::Formatter::FMT_CSV) << '\n';
    std::cout << "\nF (Python)\n" << cv::format(F, cv::Formatter::FMT_PYTHON) << '\n';
    std::cout << "\nG (Default)\n" << cv::format(G, cv::Formatter::FMT_DEFAULT) << '\n';

    cv::imshow("R", R);

    cv::waitKey();
    cv::destroyAllWindows();
}
