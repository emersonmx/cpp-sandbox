#include <catch.hpp>

#include <SDL.h>

#include <mxg/sdl/Window.hpp>

TEST_CASE("Windows can be used", "[window]") {
    REQUIRE(SDL_Init(SDL_INIT_VIDEO) == 0);

    mxg::sdl::Window window;

    SECTION("open is false when instantiated") {
        REQUIRE(window.isOpen() == false);
    }

    window.create("Test Window", {640, 480});

    SECTION("creating without call create results in undefined behavior") {
        mxg::sdl::Window windowError{};
        REQUIRE_FALSE(windowError.isOpen());
        windowError.create("Test Window", {640, 480});
        REQUIRE(windowError.isOpen());
    }
    SECTION("creating changes open to true") {
        REQUIRE(window.isOpen() == true);
    }
    SECTION("creating with title changes it value") {
        REQUIRE(window.getTitle() == "Test Window");
    }
    SECTION("creating with size changes it value") {
        auto size = window.getSize();
        REQUIRE(size.width >= 640);
        REQUIRE(size.height >= 480);
    }
    SECTION("closing changes open to false") {
        window.close();
        REQUIRE(window.isOpen() == false);
    }

    window.close();

    SDL_Quit();
}
