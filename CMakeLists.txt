cmake_minimum_required(VERSION 3.22)
project(imageconstruct)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

add_executable(imageconstruct main.cpp Core/Color.h Core/Map.h Core/types.h Formats/NetPPM8.cpp Formats/NetPPM8.h Formats/NetPPM16.cpp Formats/NetPPM16.h Formats/NetPBM.cpp Formats/NetPBM.h)
