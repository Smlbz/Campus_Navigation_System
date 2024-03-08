cmake_minimum_required(VERSION 3.12)

project(OPENGL)

set(CMAKE_CXX_STANDARD 20)

include_directories(
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/include
)

link_directories(
	SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/lib
)

add_subdirectory(wrapper)

aux_source_directory(. SRCS)

add_executable(QDU_Campus_Navigation ${SRCS} "main.cpp" "glad.c")

target_link_libraries(QDU_Campus_Navigation glfw3_mt.lib wrapper)