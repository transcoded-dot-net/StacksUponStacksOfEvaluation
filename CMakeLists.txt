cmake_minimum_required(VERSION 3.26)
project(StacksUponStacksOfEvaluation)

set(CMAKE_CXX_STANDARD 17)

add_executable(StacksUponStacksOfEvaluation main.cpp
        StackEvaluator.cpp
        StackEvaluator.h)
