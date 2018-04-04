#include <catch.hpp>

#include <SDL.h>

#include <mxg/sdl/Window.hpp>

TEST_CASE("Windows can be created and closed", "[window]") {
    REQUIRE(SDL_Init(SDL_INIT_VIDEO) == 0);

    mxg::sdl::Window window;

    SECTION("creating without call create results in undefined behavior") {
        REQUIRE(static_cast<SDL_Window*>(window) == nullptr);
        window.create("Test Window", {640, 480});
        REQUIRE(static_cast<SDL_Window*>(window) != nullptr);
    }
    SECTION("closing invalidates window") {
        window.create("Test Window", {640, 480});
        REQUIRE(static_cast<SDL_Window*>(window) != nullptr);
        window.close();
        REQUIRE(static_cast<SDL_Window*>(window) == nullptr);
    }
    SECTION("open is false when instantiated") {
        REQUIRE(window.isOpen() == false);
    }
    SECTION("creating changes open to true") {
        window.create("Test Window", {640, 480});
        REQUIRE(window.isOpen() == true);
    }
    SECTION("closing changes open to false") {
        window.close();
        REQUIRE(window.isOpen() == false);
    }
    SECTION("creating with title changes it value") {
        window.create("Test Window", {640, 480});
        REQUIRE(window.getTitle() == "Test Window");
    }
    SECTION("creating with size changes it value") {
        window.create("Test Window", {640, 480});
        auto size = window.getSize();
        REQUIRE(size.width >= 640);
        REQUIRE(size.height >= 480);
    }

    SDL_Quit();
}
