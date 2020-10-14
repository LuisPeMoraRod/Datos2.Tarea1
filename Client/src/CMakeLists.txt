set(BINARY ${CMAKE_PROJECT_NAME})

find_package(Qt5Widgets REQUIRED)

#add_executable(Client main.cpp window.cpp window.h socketclient.cpp socketclient.h)
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})

target_link_libraries(${BINARY}_run Qt5::Widgets)

#target_link_libraries(Client Qt5::Widgets)
