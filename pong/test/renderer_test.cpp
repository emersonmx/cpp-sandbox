#include <catch.hpp>

#include <SDL.h>

#include <mxg/Window.hpp>
#include <mxg/Renderer.hpp>

TEST_CASE("Renderer can be used", "[renderer]") {
    REQUIRE(SDL_Init(SDL_INIT_VIDEO) == 0);

    mxg::Window window;

    window.create("Test Window", {640, 480});

    mxg::Renderer renderer{window};

    SECTION("creating changes clear color to black") {
        mxg::Color color = renderer.getClearColor();
        REQUIRE(color.red == 0);
        REQUIRE(color.green == 0);
        REQUIRE(color.blue == 0);
        REQUIRE(color.alpha == 255);
    }
    SECTION("clearing without color changes clear color to black") {
        renderer.clear();
        renderer.present();
        mxg::Color color = renderer.getClearColor();
        REQUIRE(color.red == 0);
        REQUIRE(color.green == 0);
        REQUIRE(color.blue == 0);
        REQUIRE(color.alpha == 255);
    }

    window.close();

    SDL_Quit();
}
