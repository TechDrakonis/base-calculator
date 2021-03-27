cmake_minimum_required(VERSION 3.17)
project(Base_calculator)

set(CMAKE_CXX_STANDARD 20)

add_executable(Base_calculator main.cpp Base.cpp Base.hpp)