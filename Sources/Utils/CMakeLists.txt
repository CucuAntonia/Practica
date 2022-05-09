cmake_minimum_required(VERSION 3.0)
project(Utils)

set(LibrarySources
	Utils.h
	Utils.cpp
)

add_definitions(-DUTILS_EXPORT)

add_library(${PROJECT_NAME} SHARED ${LibrarySources})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
