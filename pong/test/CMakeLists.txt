include(${PROJECT_SOURCE_DIR}/cmake/libs/catch.cmake)
#include(${PROJECT_SOURCE_DIR}/cmake/libs/fakeit.cmake)

# Tests
file(GLOB SRCS
    _main.cpp
    *_test.cpp
    sdl/*_test.cpp
)

include_directories(
    ${CATCH_INCLUDE_DIR}
    #${FAKEIT_INCLUDE_DIR}
)

add_executable(${PROJECT_NAME}-tests ${SRCS})
add_dependencies(${PROJECT_NAME}-tests
    catch
    #fakeit
    mxgsdl
)

target_link_libraries(${PROJECT_NAME}-tests
    mxgsdl

    ${SDL2_LIBRARIES}
)
