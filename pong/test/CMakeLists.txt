include(${PROJECT_SOURCE_DIR}/cmake/libs/catch.cmake)
#include(${PROJECT_SOURCE_DIR}/cmake/libs/fakeit.cmake)

# Tests
file(GLOB SRCS *.cpp)

include_directories(
    ${CATCH_INCLUDE_DIR}
    #${FAKEIT_INCLUDE_DIR}
)

add_executable(${PROJECT_NAME}-tests ${SRCS})
add_dependencies(${PROJECT_NAME}-tests
    catch
    #fakeit
)

#target_link_libraries(${PROJECT_NAME}-tests
#)
