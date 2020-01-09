#include <mng/main_loop.h>

#include <mng/engine.h>

namespace mng {

DefaultMainLoop::DefaultMainLoop(Engine& engine)
    : engine_{&engine}
{
}

void DefaultMainLoop::processEvents(SDL_Event& event)
{
    if (event.type == SDL_QUIT) {
        engine_->quit();
    }
}

void DefaultMainLoop::fixedUpdate(double delta)
{
}

void DefaultMainLoop::update(double delta)
{
}

void DefaultMainLoop::render()
{
}

} /* namespace mng */
