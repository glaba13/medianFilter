cmake_minimum_required(VERSION 3.14)
project(median)

set(CMAKE_CXX_STANDARD 14)

add_executable(median main.cpp ImageParser.cpp ImageParser.h ImageBuilder.cpp ImageBuilder.h Image.cpp Image.h Filter.cpp Filter.h MedianFilter.cpp MedianFilter.h)