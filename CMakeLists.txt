cmake_minimum_required(VERSION 3.30)
project(VPN)
set(CMAKE_CXX_STANDARD 23)

include_directories(include)
include_directories(src)

add_executable(VPN
        src/main.cpp
)