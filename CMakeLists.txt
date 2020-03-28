cmake_minimum_required(VERSION 3.15)

project(BinaryStereo)

set(CMAKE_CXX_STANDARD 14) # OpenCV requires at least C++ 11

## Load OpenCV via `pkg-config`
# See https://stackoverflow.com/a/57224542/1700776
# the `pkg_check_modules` function is created with this call
find_package(PkgConfig REQUIRED)

# these calls create special `PkgConfig::<MODULE>` variables
pkg_check_modules(OPENCV REQUIRED IMPORTED_TARGET opencv4)

## Include project sources
include_directories(.)

## Build executable
add_executable(BinaryStereo
        main.cpp
        BinaryStereo.cpp
        BinaryStereo.h
        CommonFunc.cpp
        CommonFunc.h
        IStereoAlg.cpp
        IStereoAlg.h
)

# Link OpenCV libs
target_link_libraries(BinaryStereo PUBLIC
        PkgConfig::OPENCV
)

