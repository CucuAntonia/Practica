cmake_minimum_required(VERSION 3.0)
project(ImageProcessingApp)

set( AppSources
	main.cpp
)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(${PROJECT_NAME} ${AppSources})

add_dependencies(${PROJECT_NAME}
	Algorithms
	Utils
)

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_SOURCE_DIR}/Algorithms
)


target_link_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

target_link_libraries(${PROJECT_NAME}
	Algorithms.lib
	Utils.lib
	${OpenCV_LIBS}
	
)

target_include_directories(${PROJECT_NAME} PUBLIC Utils)

target_link_directories(${PROJECT_NAME} PUBLIC Utils/)


