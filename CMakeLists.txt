cmake_minimum_required(VERSION 4.3)
project(my_toy)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        6.0
        GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(raylib)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

if (MSVC)
    target_compile_options(my_toy PRIVATE /utf-8)
endif()
