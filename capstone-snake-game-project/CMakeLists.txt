cmake_minimum_required(VERSION 3.7)
project(SnakeGame VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-std=c++17)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# Add all cpp source files under the src directory
file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
include_directories(src)

IF (WIN32)
    file(COPY ${PROJECT_SOURCE_DIR}/lib/SDL2/bin/SDL2.dll DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY ${PROJECT_SOURCE_DIR}/lib/SDL2TTF/bin/SDL2_ttf.dll DESTINATION ${CMAKE_BINARY_DIR})
ENDIF()

# find_package(SDL2_ttf REQUIRED)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
find_package(SDL2TTF REQUIRED)
include_directories(${SDL2TTF_INCLUDE_DIR})

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2TTF_LIBRARY})
