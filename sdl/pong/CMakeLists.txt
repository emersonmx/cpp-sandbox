cmake_minimum_required(VERSION 3.10)
project(pong)

set(pong_VERSION_MAJOR 0)
set(pong_VERSION_MINOR 1)
set(pong_VERSION_REVISION 0)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configs/config.cmake)

# Options
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configs/options.cmake)

# Compiler settings
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configs/compiler.cmake)

# Libs
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configs/libs.cmake)

# Build settings
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configs/build.cmake)
