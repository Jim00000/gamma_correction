#include <cmath>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "gamma_correction.hpp"

using namespace cv;

__global__ void 
_gamma_correction_kernel_(const unsigned char* src, unsigned char* dst, const size_t rows, const size_t cols, const float gamma)
{
    const int idx = blockIdx.x * blockDim.x + threadIdx.x;
    const int idy = blockIdx.y * blockDim.y + threadIdx.y;
    const int id = idy * cols + idx;

    if(id >= rows * cols) {
        return;
    }

    const float inv_gamma = 1.0f / gamma;
    float value = round(pow(src[id] / 255.0f, inv_gamma) * 255.0f);
    value = (value > 255.0f) ? 255.0f : value;
    value = (value < 0) ? 0 : value;

    dst[id] = static_cast<uchar>(value);

}

void
_process_cuda(const unsigned char* src, unsigned char* dst, const size_t rows, const size_t cols, const float gamma)
{
    const size_t ARRAY_SIZE = rows * cols;
	const size_t ARRAY_BYTES = ARRAY_SIZE * sizeof(unsigned char);
    unsigned char* d_src;
    unsigned char* d_dst;
    cudaMalloc((void**) &d_src, ARRAY_BYTES);
	cudaMalloc((void**) &d_dst, ARRAY_BYTES);
    cudaMemcpy(d_src, src, ARRAY_BYTES, cudaMemcpyHostToDevice);

    const static int THREADS_COUNT = 8;
    dim3 threads(THREADS_COUNT, THREADS_COUNT);
    dim3 blocks(rows / threads.x + 1, cols / threads.y + 1);

    _gamma_correction_kernel_<<<blocks, threads>>>(d_src, d_dst, rows, cols, gamma);

    cudaMemcpy(dst, d_dst, ARRAY_BYTES, cudaMemcpyDeviceToHost);
    cudaFree(d_src);
	cudaFree(d_dst);
}

void
gamma_correction::_process(const cv::Mat& src, cv::Mat& dst, const float gamma)
{
    std::cout << "Run with CUDA" << std::endl;
    Mat bgr[3];
    Mat d_bgr[3];
    split(src, bgr);
    split(dst, d_bgr);
    _process_cuda(bgr[0].data, d_bgr[0].data, src.rows, src.cols, gamma);
    _process_cuda(bgr[1].data, d_bgr[1].data, src.rows, src.cols, gamma);
    _process_cuda(bgr[2].data, d_bgr[2].data, src.rows, src.cols, gamma);
    cv::merge(d_bgr, 3, dst);
}
