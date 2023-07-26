cmake_minimum_required(VERSION 3.25)

set(PROJECT HelloWorld)
project(${PROJECT} LANGUAGES CXX)

#Export the compile commands for the LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

find_package(fmt REQUIRED)


add_executable(${PROJECT} src/helloWorld.cpp)
target_link_libraries(${PROJECT} PRIVATE fmt::fmt)