cmake_minimum_required(VERSION 4.3)
project(my_toy)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "" FORCE)

include(FetchContent)

set(FETCHCONTENT_BASE_DIR ${CMAKE_SOURCE_DIR}/build/_deps CACHE PATH "" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 6.0
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(raylib)

FetchContent_Declare(
        raygui
        GIT_REPOSITORY https://github.com/raysan5/raygui.git
        GIT_TAG 4.0
        GIT_SHALLOW TRUE
)
FetchContent_GetProperties(raygui)
if (NOT raygui_POPULATED)
    FetchContent_MakeAvailable(raygui)
    add_library(raygui INTERFACE)
    target_include_directories(raygui INTERFACE ${raygui_SOURCE_DIR}/src)
    target_link_libraries(raygui INTERFACE raylib)
endif ()

add_executable(${PROJECT_NAME}
        src/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
        src
        ${raylib_SOURCE_DIR}/src
        ${raygui_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib raygui)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)
endif ()