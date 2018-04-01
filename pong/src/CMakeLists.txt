include_directories(
    ${PROJECT_SOURCE_DIR}/src
)

# Targets
add_library(mxg-sdl
    mxg/Size.cpp
    mxg/Window.cpp
    mxg/sdl/Window.cpp
    mxg/Renderer.cpp
    mxg/sdl/Renderer.cpp
)

add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME}
    mxg-sdl

    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
)
