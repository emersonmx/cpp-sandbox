include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(src)

if (BUILD_TESTS)
    add_subdirectory(test)
endif()
