cmake_minimum_required(VERSION 3.25)

set(PROJECT HelloWorld)
project(${PROJECT} LANGUAGES CXX)

#Export the compile commands for the LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)


find_package(fmt REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(Freetype REQUIRED)
find_package(imgui REQUIRED)
find_package(implot REQUIRED)

set(LIBRARIES
    fmt::fmt
    glfw
    Freetype::Freetype
    ${OPENGL_LIBRARIES}
    imgui::imgui
    implot::implot
)

set(FileDialog
    lib/ImGuiFileDialog/ImGuiFileDialog.h
    lib/ImGuiFileDialog/ImGuiFileDialog.cpp
)

set(SOURCE
    src/helloWorld.cpp
)

add_executable(${PROJECT} ${FileDialog} ${SOURCE})
target_link_libraries(${PROJECT} PRIVATE ${LIBRARIES})
