cmake_minimum_required(VERSION 3.10)

project(strahl)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(strahl src/main.cpp src/vec.cpp src/ray.cpp)
target_compile_options(strahl PRIVATE -Wall -Wextra -pedantic -Werror)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

include_directories(${CMAKE_SOURCE_DIR}/inc)
link_directories(${CMAKE_SOURCE_DIR}/lib)

target_link_libraries(strahl ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
