#include <cstdlib>
#include <cmath>
#include <string>
#include "gamma_correction_test.hpp"

using namespace cv;

int
main(int argc, char* argv[])
{
    Mat src = imread("Lenna.png", CV_LOAD_IMAGE_COLOR);
    std::string cmd = "convert -delay 20 ";
    for(size_t i = 1; i <= 30 ; i++) {
        gamma_correction_test gc = gamma_correction_test(src, i / 10.0f);
        std::string filename = "output" + std::to_string(i) + ".png";
        imwrite(filename, gc.result());
        cmd += (filename + " ");
    }

    cmd += "animated.gif";
    system(cmd.c_str());

    return 0;
}