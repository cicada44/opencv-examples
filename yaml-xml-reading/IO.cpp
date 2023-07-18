//-----------------------------------------------------------------------------
//
// Example for YAML/XML images input/output in C++ with OpenCV.
//
//-----------------------------------------------------------------------------

#include <opencv2/opencv.hpp>

#include <iostream>

#include <string>

class MyData {
public:
    MyData() : A(0), X(0), id() {}

    explicit MyData(int) : A(97), X(CV_PI), id("mydata1234") {}

    void write(cv::FileStorage os) const {
        os << "{"
           << "A" << A << "X" << X << "id" << id << "}";
    }

    void read(const cv::FileNode& node)  // Read serialization for this class
    {
        A = static_cast<int>(node["A"]);
        X = static_cast<double>(node["X"]);
        id = static_cast<std::string>(node["id"]);
    }

    int A;
    double X;
    std::string id;
};

/* These write and read functions must be defined for the serialization in FileStorage to work. */
static void write(cv::FileStorage& fs, const std::string&, const MyData& x) { x.write(fs); }

static void read(const cv::FileNode& node, MyData& x, const MyData& default_value = MyData()) {
    if (node.empty())
        x = default_value;
    else
        x.read(node);
}

/* This function will print our custom class to the console. */
static std::ostream& operator<<(std::ostream& out, const MyData& m) {
    out << "{ id = " << m.id << ", ";
    out << "X = " << m.X << ", ";
    out << "A = " << m.A << "}";
    return out;
}

int main() {
    std::string filename = "output.yaml";

    {
        cv::Mat R = cv::Mat_<uchar>::eye(3, 3), T = cv::Mat_<double>::zeros(3, 1);
        MyData m(1);
        cv::FileStorage fs(filename, cv::FileStorage::WRITE);
        fs << "iterationNr" << 100;
        fs << "strings"
           << "[";  // text - string sequence
        fs << "image1.jpg"
           << "Awesomeness"
           << "../data/baboon.jpg";
        fs << "]";        // close sequence
        fs << "Mapping";  // text - mapping
        fs << "{"
           << "One" << 1;
        fs << "Two" << 2 << "}";
        fs << "R" << R;
        fs << "T" << T;
        fs << "MyData" << m;
        fs.release();
        std::cout << "Write Done.\n";
    }

    filename = "output.yaml";
    {
        std::cout << "\nReading: \n";
        cv::FileStorage fs;
        fs.open(filename, cv::FileStorage::READ);
        int itNr;
        itNr = static_cast<int>(fs["iterationNr"]);
        std::cout << itNr;

        cv::FileNode n = fs["strings"];
        if (n.type() != cv::FileNode::SEQ) {
            std::cerr << "strings is not a sequence! FAIL\n";
            return 1;
        }

        cv::FileNodeIterator it = n.begin(), it_end = n.end();
        for (; it != it_end; ++it) std::cout << static_cast<std::string>(*it) << '\n';

        n = fs["Mapping"];
        std::cout << "Two " << (int)(n["Two"]) << "; ";
        std::cout << "One " << (int)(n["One"]) << "\n\n";

        MyData m;

        cv::Mat R, T;

        fs["R"] >> R;
        fs["T"] >> T;

        fs["MyData"] >> m;
        std::cout << "\nR = " << R << '\n';
        std::cout << "T = " << T << "\n\n";
        std::cout << "MyData = " << '\n' << m << "\n\n";

        std::cout << "Attempt to read NonExisting (should initialize the data structure with its default).";
        fs["NonExisting"] >> m;
        std::cout << "\nNonExisting = \n" << m << '\n';
    }
}
