cmake_minimum_required(VERSION 3.12)

project(OPENGL)

set(CMAKE_CXX_STANDARD 20)

aux_source_directory(. SRCS)

add_executable(QDU_Campus_Navigation ${SRCS} "fun.h" "fun.cpp")