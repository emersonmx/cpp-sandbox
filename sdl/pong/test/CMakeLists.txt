include(${PROJECT_SOURCE_DIR}/cmake/configs/libs/catch2.cmake)

# Tests
file(GLOB SRCS *.cpp)

add_executable(pong-tests ${SRCS})
