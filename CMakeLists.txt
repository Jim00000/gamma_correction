cmake_minimum_required (VERSION 3.0 FATAL_ERROR)
project (gamma-correction VERSION 1.0.0 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS_DEBUG  "-Wall -O0 -g")
set (CMAKE_CXX_FLAGS_RELEASE "-Wall -O2")
set (CMAKE_BUILD_TYPE Debug CACHE STRING "Build Type" FORCE) 
set_property (CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug;Release")

set (BUILD_WITH_CUDA OFF CACHE BOOL "Build with CUDA")

find_package (OpenMP REQUIRED)
find_package (OpenCV REQUIRED)
find_package (CUDA)

if (OpenMP_FOUND)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif ()

if (OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
endif ()

include_directories (include/)
add_subdirectory (src/)
add_subdirectory (test/)