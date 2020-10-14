set(BINARY ${CMAKE_PROJECT_NAME}_tst)

find_package(Qt5Widgets REQUIRED)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)

target_link_libraries(${CMAKE_PROJECT_NAME}_lib Qt5::Widgets)