#ifndef MNG_ENGINE_H
#define MNG_ENGINE_H

#include <string>

#include <SDL.h>

namespace mng {

class MainLoop;

class Engine {
public:
    struct Settings {
        struct Window {
            std::string title;
            int width;
            int height;
        };
        struct Renderer {
            SDL_Color clear_color;
            bool vsync;
        };
        struct Physics {
            double fps;
        };

        Window window;
        Renderer renderer;
        Physics physics;
    };

    Engine();

    Settings getDefaultSettings() const;
    void updateSettings(Settings settings);

    void setMainLoop(MainLoop& loop);

    SDL_Window* getWindow() const;
    SDL_Renderer* getRenderer() const;

    void run();
    void quit();

private:
    double getFixedUpdateDelta() const;

    void initialize();
    void finalize();

    bool setupWindow();
    bool setupRenderer();

    void processEvents();
    void fixedUpdate();
    void update(double delta);
    void render();

    bool running_;
    double physicsTickCount_;
    Settings settings_;
    MainLoop* loop_;

    SDL_Window* window_;
    SDL_Renderer* renderer_;
};

} /* namespace mng */

#endif /* MNG_ENGINE_H */
