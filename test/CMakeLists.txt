cmake_minimum_required (VERSION 3.0 FATAL_ERROR)

configure_file (Lenna.png ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable (test-gc test.cpp gamma_correction_test.cpp)

if (CUDA_FOUND AND BUILD_WITH_CUDA)
    target_link_libraries (test-gc gamma-correction-culib gamma-correction-lib ${OpenCV_LIBS})
else ()
    target_link_libraries (test-gc gamma-correction-lib ${OpenCV_LIBS})
endif ()

enable_testing ()
add_test (testcase01 test-gc)