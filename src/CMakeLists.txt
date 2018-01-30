cmake_minimum_required (VERSION 3.0 FATAL_ERROR)

add_library (gamma-correction-lib STATIC gamma_correction.cpp)
add_library (gamma-correction-shared-lib SHARED gamma_correction.cpp)

if (CUDA_FOUND AND BUILD_WITH_CUDA)
    set (CUDA_SEPARABLE_COMPILATION ON)
    add_definitions (-DUSE_CUDA)
    cuda_add_library(gamma-correction-culib gamma_correction.cu gamma_correction.cpp)
endif ()