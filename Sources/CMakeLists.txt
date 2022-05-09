cmake_minimum_required(VERSION 3.0)

project(PracticaSpring2022)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../PracticaSpring2022_Binaries")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_subdirectory(Algorithms)
add_subdirectory(ImageProcessingApp)
add_subdirectory(Utils)




