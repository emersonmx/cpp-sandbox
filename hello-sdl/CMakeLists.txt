cmake_minimum_required(VERSION 3.10)

project(hello-sdl)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2 >= 2.0.0)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image >= 2.0.0)

include_directories(${PROJECT_SOURCE_DIR}
    ${SDL2_INCLUDE_DIRS}
    ${SDL2IMAGE_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}
    src/hello-sdl.cpp
)

target_link_libraries(${PROJECT_NAME}
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
)
