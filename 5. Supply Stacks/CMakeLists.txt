cmake_minimum_required(VERSION 3.2)
project(main)

include_directories(${CMAKE_SOURCE_DIR})

set(MAIN_SRC  ${CMAKE_SOURCE_DIR}/src/main.cpp)
set(LLIST_SRC ${CMAKE_SOURCE_DIR}/src/llist/llist.cpp)
set(STACK_SRC ${CMAKE_SOURCE_DIR}/src/stack/stack.cpp)

add_executable(${PROJECT_NAME} ${MAIN_SRC} ${LLIST_SRC} ${STACK_SRC})
