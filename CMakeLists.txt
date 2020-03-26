cmake_minimum_required(VERSION 3.15)
project(BinaryStereo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(/usr/local/opt/opencv/include/opencv4) # Install dir of `brew install opencv`

add_executable(BinaryStereo
        main.cpp
        BinaryStereo.cpp
        BinaryStereo.h
        CommonFunc.cpp
        CommonFunc.h
        IStereoAlg.cpp
        IStereoAlg.h
)
