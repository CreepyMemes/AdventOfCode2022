cmake_minimum_required(VERSION 3.2)
project(main)

include_directories(${CMAKE_SOURCE_DIR})

set(MAIN_SRC       ${CMAKE_SOURCE_DIR}/src/main.cpp)
set(LINKEDLIST_SRC ${CMAKE_SOURCE_DIR}/src/linkedlist/linkedlist.cpp)

add_executable(${PROJECT_NAME} ${MAIN_SRC} ${LINKEDLIST_SRC})
