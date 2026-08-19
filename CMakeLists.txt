cmake_minimum_required(VERSION 4.3)
project(my_toy)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "" FORCE)

include(FetchContent)

set(FETCHCONTENT_BASE_DIR ${CMAKE_SOURCE_DIR}/build/_deps CACHE PATH "" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

# Raylib
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 6.0
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(raylib)

# Raygui
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
        thirdparty/imgui/imgui.cpp
        thirdparty/imgui/imgui_demo.cpp
        thirdparty/imgui/imgui_draw.cpp
        thirdparty/imgui/imgui_tables.cpp
        thirdparty/imgui/imgui_widgets.cpp
        thirdparty/rlImGui/rlImGui.cpp
        src/actor/actor.cpp
        src/actor/actor.h
        src/core/global_actor_array.cpp
        src/core/global_actor_array.h
        src/actor/player/player.cpp
        src/actor/player/player.h
)

target_include_directories(${PROJECT_NAME} PRIVATE
        src
        ${raylib_SOURCE_DIR}/src
        ${raygui_SOURCE_DIR}/src
        thirdparty/imgui
        thirdparty/imgui/backends
        thirdparty/rlImGui
        thirdparty/rlImGui/extras
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib raygui)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /utf-8)
endif ()