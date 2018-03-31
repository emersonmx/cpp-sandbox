#include <catch.hpp>

#include <utils.hpp>
#include <mxg/Window.hpp>

TEST_CASE("Windows can be created and closed", "[window]") {
    pong::initSystems();

    mxg::Window window;

    window.create("Test Window", {640, 480});

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

    pong::quitSystems();
}
