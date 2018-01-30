#include "gamma_correction.hpp"

using namespace cv;

int main()
{
    Mat src = imread("Lenna.png");
    gamma_correction gc = gamma_correction(src, 0.5f);
    imshow("test", gc.result());
    waitKey();
    return 0;
}