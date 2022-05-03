cmake_minimum_required(VERSION 3.0)
project(Algorithms)

set(LibrarySources
	Algorithms.h
	Algorithms.cpp
)

add_definitions(-DALGORITHMS_EXPORT)

add_library(${PROJECT_NAME} SHARED ${LibrarySources})
