cmake_minimum_required(VERSION 3.23)
project(Tetris)

set(CMAKE_CXX_STANDARD 20)

add_executable(Tetris Matrix.cpp Tetramine.cpp main.cpp)
