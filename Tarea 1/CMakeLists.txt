cmake_minimum_required(VERSION 3.17)
project(Tarea_1)

set(CMAKE_CXX_STANDARD 20)
find_package(Qt5Widgets REQUIRED)

add_executable(Tarea_1 main.cpp Vertex.cpp Vertex.h VertexList.cpp VertexList.h AdjacentNode.cpp AdjacentNode.h NodesList.cpp NodesList.h)
target_link_libraries(Tarea_1 Qt5::Widgets)