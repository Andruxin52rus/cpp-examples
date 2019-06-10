cmake_minimum_required(VERSION 3.4.0)
set(CMAKE_CXX_STANDARD 11)

project(joining_thread_demo CXX)

find_package(Threads)

add_executable(${PROJECT_NAME} test.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})