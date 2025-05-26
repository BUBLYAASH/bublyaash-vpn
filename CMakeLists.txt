cmake_minimum_required(VERSION 3.30)
project(VPN)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

include_directories(include)
include_directories(src)

add_executable(VPN
        src/main.cpp
)

target_link_libraries(VPN
        Qt5::Core
        Qt5::Widgets
)