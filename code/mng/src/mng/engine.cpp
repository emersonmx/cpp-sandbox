#include <mng/engine.h>

#include <SDL.h>

#include <mng/timer.h>
#include <mng/main_loop.h>

namespace mng {

Engine::Engine()
    : running_{true},
      physicsTickCount_{0.0},
      settings_{Engine::getDefaultSettings()},
      window_{nullptr},
      renderer_{nullptr}
{
}

Engine::Settings Engine::getDefaultSettings() const
{
    return Engine::Settings{
        .window = {
            .title = "Window",
            .width = 800,
            .height = 600
        },
        .renderer = {
            .clear_color = {0, 0, 0, SDL_ALPHA_OPAQUE},
            .vsync = true
        },
        .physics = {
            .fps = 60.0
        }
    };
}

void Engine::updateSettings(Settings settings) { settings_ = settings; }

void Engine::setMainLoop(MainLoop& loop) { loop_ = &loop; }

SDL_Window* Engine::getWindow() const { return window_; }

SDL_Renderer* Engine::getRenderer() const { return renderer_; }

void Engine::run()
{
    initialize();

    double lastCount = timer::getTicksInSeconds();
    double delta = getFixedUpdateDelta();
    while (running_) {
        double now = timer::getTicksInSeconds();
        delta = now - lastCount;
        lastCount = now;
        physicsTickCount_ += delta;

        processEvents();
        fixedUpdate();
        update(delta);
        render();
    }

    finalize();
}

void Engine::quit()
{
    running_ = false;
}

double Engine::getFixedUpdateDelta() const
{
    return 1.0 / settings_.physics.fps;
}

void Engine::initialize()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_INFO);

    running_ = setupWindow() && setupRenderer();
}

void Engine::finalize()
{
    if (renderer_) {
        SDL_DestroyRenderer(renderer_);
    }

    if (window_) {
        SDL_DestroyWindow(window_);
    }

    SDL_Quit();
}

bool Engine::setupWindow()
{
    uint32_t flags = SDL_WINDOW_SHOWN;

    window_ = SDL_CreateWindow(
        settings_.window.title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        settings_.window.width, settings_.window.height,
        flags
    );

    if (window_ == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO,
            "Couldn't create SDL Window\n\tError: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

bool Engine::setupRenderer()
{
    uint32_t flags = SDL_RENDERER_ACCELERATED;
    if (settings_.renderer.vsync) {
        flags |= SDL_RENDERER_PRESENTVSYNC;
    }

    if (window_ == nullptr) {
        return false;
    }

    renderer_ = SDL_CreateRenderer(window_, -1, flags);
    SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_BLEND);

    if (renderer_ == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_VIDEO,
            "Couldn't create SDL Renderer\n\tError: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void Engine::processEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        loop_->processEvents(event);
    }
}

void Engine::fixedUpdate()
{
    if (physicsTickCount_ <= getFixedUpdateDelta()) {
        return;
    }

    loop_->fixedUpdate(getFixedUpdateDelta());
    physicsTickCount_ -= getFixedUpdateDelta();
}

void Engine::update(double delta)
{
    loop_->update(delta);
}

void Engine::render()
{
    SDL_Color color = settings_.renderer.clear_color;
    SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer_);

    loop_->render();

    SDL_RenderPresent(renderer_);
}

} /* namespace mng */
