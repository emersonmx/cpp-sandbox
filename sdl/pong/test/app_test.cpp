#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <pong/Application.hpp>

TEST_CASE("Run Application", "[application]") {
    pong::PongApp app;
    REQUIRE(app.run() == 0);
}
