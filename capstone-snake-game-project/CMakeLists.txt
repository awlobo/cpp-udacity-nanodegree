cmake_minimum_required(VERSION 3.7)
project(SnakeGame VERSION 1.0.0)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt first.")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS} -std=c++17 -pthread")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# Add all cpp source files under the src directory
file(GLOB SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
include_directories(src)

# Copy res folder to build directory
set (SRC_RES_FOLDER "${CMAKE_SOURCE_DIR}/res")
set (DEST_RES_FOLDER "${CMAKE_CURRENT_BINARY_DIR}/res")
if (WIN32)
    file(TO_NATIVE_PATH "${DEST_RES_FOLDER}" _dstDir)
    file(TO_NATIVE_PATH "${SRC_RES_FOLDER}" _srcDir)
    execute_process(COMMAND cmd.exe /c mklink /J "${_dstDir}" "${_srcDir}")
else()
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink ${SRC_RES_FOLDER} ${DEST_RES_FOLDER} 
        DEPENDS ${DEST_RES_FOLDER}
        COMMENT "Create symbolic link for resources folder"
    )
endif()


# Copy dll libries in build directory (Only for Windows)
IF (WIN32)
    file(COPY ${PROJECT_SOURCE_DIR}/lib/SDL2/bin/SDL2.dll DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY ${PROJECT_SOURCE_DIR}/lib/SDL2TTF/bin/SDL2_ttf.dll DESTINATION ${CMAKE_BINARY_DIR})
ENDIF()

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
find_package(SDL2TTF REQUIRED)
include_directories(${SDL2TTF_INCLUDE_DIR})

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2TTF_LIBRARY})
