#ifndef __GAMMA_CORRECTION_HPP__
#define __GAMMA_CORRECTION_HPP__

#include <opencv2/opencv.hpp>

class gamma_correction
{
public:
    gamma_correction(cv::Mat& src, const float gamma = 1.0f);
    virtual ~gamma_correction();
    cv::Mat& result();
protected:
    virtual void _process(const cv::Mat& src, cv::Mat& dst, const float gamma);

private:
    cv::Mat _result;
};

#endif