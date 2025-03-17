cmake_minimum_required(VERSION 3.16)
project(snakes)
set(CMAKE_C_FLAGS "--std=c2x")
set(CMAKE_C_COMPILER "/usr/bin/clang")

file(GLOB SourceFiles src/*.c)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SourceFiles})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2_ttf)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
