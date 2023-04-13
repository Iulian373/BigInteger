cmake_minimum_required(VERSION 3.24)
project(BigInteger C)

set(CMAKE_C_STANDARD 99)

add_executable(BigInteger main.c bigInteger.h bigInteger.c)
