# Targets
add_library(mxgsdl
    mxg/Size.cpp
    mxg/sdl/Window.cpp
    mxg/sdl/Renderer.cpp
)

add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME}
    mxgsdl

    ${SDL2_LIBRARIES}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
)
