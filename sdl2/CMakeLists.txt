include_directories(smartptr_test
    ${SDL2_INCLUDE_DIRS}
)
add_executable(smartptr_test smartptr_test.cpp)
target_link_libraries(smartptr_test
    ${SDL2_LIBRARIES}
)
