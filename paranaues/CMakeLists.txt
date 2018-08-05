cmake_minimum_required(VERSION 3.11)
project(paranaues LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(paranaues_VERSION_MAJOR 0)
set(paranaues_VERSION_MINOR 1)
set(paranaues_VERSION_REVISION 0)

# Configs
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Options
option(BUILD_DEFAULT_PARANAUES "Build default paranaues" ON)
option(BUILD_SDL2_PARANAUES "Build SDL2 paranaues" ON)

# Compiler settings
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING
        "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
        FORCE)
endif(NOT CMAKE_BUILD_TYPE)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic")
endif()

if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fmessage-length=0")
endif()
if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmessage-length=0")
endif()

if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__NO_INLINE__ -D_USE_MATH_DEFINES")
    set(CMAKE_EXE_LINKER_FLAGS "-Wl,--subsystem,windows")
endif()

# Libs
include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)

# Build settings

if (BUILD_DEFAULT_PARANAUES)
    add_subdirectory(default)
endif()

if (BUILD_SDL2_PARANAUES)
    add_subdirectory(sdl2)
endif()
