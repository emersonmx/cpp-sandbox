cmake_minimum_required(VERSION 3.10)

project(mng VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2>=2.0.0)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/src
)

# Build settings
add_executable(mng_test
    test/main.cpp
    src/mng/timer.cpp
    src/mng/engine.cpp
    src/mng/main_loop.cpp
)

target_link_libraries(mng_test
    ${SDL2_LIBRARIES}
)
