cmake_minimum_required(VERSION 3.7)
project(SnakeGame VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-std=c++17)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

file(GLOB SOURCES "src/*.cpp")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

IF (WIN32)
    file(COPY ${PROJECT_SOURCE_DIR}/lib/SDL2-2.0.20/bin/SDL2.dll DESTINATION ${CMAKE_BINARY_DIR})
ENDIF()

# find_package(SDL2_ttf REQUIRED)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(${PROJECT_NAME} ${SOURCES})
string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
