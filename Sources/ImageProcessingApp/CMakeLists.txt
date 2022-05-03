cmake_minimum_required(VERSION 3.0)
project(ImageProcessingApp)

set( AppSources
	main.cpp
)

add_executable(${PROJECT_NAME} ${AppSources})

add_dependencies(${PROJECT_NAME}
	Algorithms
)

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_SOURCE_DIR}/Algorithms
)

target_link_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

target_link_libraries(${PROJECT_NAME}
	Algorithms.lib
)
