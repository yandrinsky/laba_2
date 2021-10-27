cmake_minimum_required(VERSION 3.17)
project(Laba2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Laba2
        LR2.cpp
        setarray.h
        setbitsarray.h
        setlist.h
        setmachineword.h)
