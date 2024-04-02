cmake_minimum_required(VERSION 3.12)

project(OPENGL)

set(CMAKE_CXX_STANDARD 11)

add_definitions(-DDEBUG)

file(GLOB ASSETS "./assets")
file(COPY ${ASSETS} DESTINATION ${CMAKE_BINARY_DIR})

include_directories(
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/include
)

link_directories(
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/lib
)

add_subdirectory(wrapper)
add_subdirectory(application)
add_subdirectory(glFramework)

aux_source_directory(. SRCS)

add_executable(QDU_Campus_Navigation ${SRCS} "main.cpp" "glad.c" )

target_link_libraries(QDU_Campus_Navigation glfw3_mt.lib wrapper app)