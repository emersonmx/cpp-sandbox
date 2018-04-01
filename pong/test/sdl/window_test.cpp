#include <catch.hpp>

#include <SDL.h>

#include <mxg/sdl/Window.hpp>

TEST_CASE("Windows can be used", "[window]") {
    REQUIRE(SDL_Init(SDL_INIT_VIDEO) == 0);

    mxg::sdl::Window window;

    SECTION("creating without call create results in undefined behavior") {
        REQUIRE_FALSE(window.isOpen());
        window.create("Test Window", {640, 480});
        REQUIRE(window.isOpen());
    }
    SECTION("open is false when instantiated") {
        REQUIRE(window.isOpen() == false);
    }
    SECTION("creating changes open to true") {
        window.create("Test Window", {640, 480});
        REQUIRE(window.isOpen() == true);
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
    SECTION("closing changes open to false") {
        window.close();
        REQUIRE(window.isOpen() == false);
    }
    SECTION("closing invalidates window") {
        window.create("Test Window", {640, 480});
        REQUIRE(window.isOpen());
        window.close();
        REQUIRE_FALSE(window.isOpen());
    }

    SDL_Quit();
}
