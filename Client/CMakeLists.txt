cmake_minimum_required(VERSION 3.17)
project(Client)

set(CMAKE_CXX_STANDARD 17)
find_package(Qt5Widgets REQUIRED)

add_executable(Client main.cpp table.cpp table.h)
target_link_libraries(Client Qt5::Widgets)