cmake_minimum_required(VERSION 3.31)
project(Cmania C)

set(CMAKE_C_STANDARD 11)

add_executable(Cmania main.c
        network/system_network.h
        network/system_network.c
)
