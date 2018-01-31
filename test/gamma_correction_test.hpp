#ifndef __GAMMA_CORRECTION_TEST_HPP__
#define __GAMMA_CORRECTION_TEST_HPP__

#include <opencv2/opencv.hpp>
#include "gamma_correction.hpp"

class gamma_correction_test : public gamma_correction
{
public:
    gamma_correction_test(cv::Mat& src, const float gamma = 1.0f);
    virtual ~gamma_correction_test();
};

#endif