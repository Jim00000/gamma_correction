cmake_minimum_required (VERSION 3.0 FATAL_ERROR)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    configure_file (Lenna.png ${CMAKE_BINARY_DIR} COPYONLY)
else ()
    configure_file (Lenna.png ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
endif ()

add_executable (test-gc test.cpp gamma_correction_test.cpp)

if (CUDA_FOUND AND BUILD_WITH_CUDA)
    target_link_libraries (test-gc gamma-correction-culib gamma-correction-lib ${OpenCV_LIBS})
else ()
    target_link_libraries (test-gc gamma-correction-lib ${OpenCV_LIBS})
endif ()