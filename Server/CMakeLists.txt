cmake_minimum_required(VERSION 3.17)
project(Server)

set(CMAKE_CXX_STANDARD 20)
find_package(Qt5Widgets REQUIRED)

add_executable(Server main.cpp graph.cpp graph.h floydwarshall.cpp floydwarshall.h)
target_link_libraries(Server Qt5::Widgets)