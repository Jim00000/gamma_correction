cmake_minimum_required (VERSION 3.0 FATAL_ERROR)

if (CUDA_FOUND AND BUILD_WITH_CUDA)

else ()
    add_library (gamma-correction-lib STATIC gamma_correction.cpp)
    add_library (gamma-correction-shared-lib SHARED gamma_correction.cpp)
endif ()