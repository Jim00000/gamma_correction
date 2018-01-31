#include <iostream>
#include <cmath>
#include <omp.h>
#include "gamma_correction.hpp"

using namespace cv;

gamma_correction::gamma_correction(Mat& src, const float gamma)
{
    _result = Mat(src.size(), src.type());
    _process(src, _result, gamma);
}

gamma_correction::~gamma_correction()
{

}

#ifndef USE_CUDA
void
gamma_correction::_process(const cv::Mat& src, cv::Mat& dst, const float gamma)
{
    const float inv_gamma = 1.0f / gamma;
    #pragma omp parallel for collapse(2)
    for(int i = 0; i < src.rows; i++) {
        for(int j = 0; j < src.cols; j++) {
            dst.at<Vec3b>(i, j).val[0] = saturate_cast<uchar>(pow(src.at<Vec3b>(i,
                                                                                j).val[0] / 255.0f, inv_gamma) * 255.0f);
            dst.at<Vec3b>(i, j).val[1] = saturate_cast<uchar>(pow(src.at<Vec3b>(i,
                                                                                j).val[1] / 255.0f, inv_gamma) * 255.0f);
            dst.at<Vec3b>(i, j).val[2] = saturate_cast<uchar>(pow(src.at<Vec3b>(i,
                                                                                j).val[2] / 255.0f, inv_gamma) * 255.0f);
        }
    }
}
#endif

Mat&
gamma_correction::result()
{
    return _result;
}