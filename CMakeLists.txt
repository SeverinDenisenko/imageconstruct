cmake_minimum_required(VERSION 3.22)
project(imageconstruct)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

add_executable(imageconstruct src/main.cpp src/Core/Color.h src/Core/Map.h src/Core/types.h src/Formats/NetPPM8.cpp src/Formats/NetPPM8.h src/Formats/NetPPM16.cpp src/Formats/NetPPM16.h src/Formats/NetPBM.cpp src/Formats/NetPBM.h src/Formats/NetPGM8.cpp src/Formats/NetPGM8.h src/Formats/NetPGM16.cpp src/Formats/NetPGM16.h src/Opener.cpp src/Opener.h src/Core/Generators.h src/Core/Operators.h src/Core/Kernel.h src/Core/Filters.h src/Core/TiledMap.h src/Core/KernelCollection.h)
