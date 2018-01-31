#include "gamma_correction_test.hpp"

using namespace cv;

gamma_correction_test::gamma_correction_test(Mat& src, const float gamma) : gamma_correction(src, gamma)
{
    putText(result(), "gamma : " + std::to_string(gamma), Point(10, 30), 2, 1.0,
            Scalar(255, 0, 0));
}

gamma_correction_test::~gamma_correction_test()
{

}
