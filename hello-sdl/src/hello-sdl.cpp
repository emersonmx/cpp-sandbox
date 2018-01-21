#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

// Default exceptions
class Exception : public std::logic_error {
public:
    Exception(const std::string& message) : std::logic_error(message) {}
};

class RuntimeException : public std::runtime_error {
public:
    RuntimeException(const std::string& message) : std::runtime_error(message) {}
};

// SDL exceptions
class SDLException : public RuntimeException {
public:
    SDLException(const std::string& message) : RuntimeException(message) {}
};

class SDLImageException : public SDLException {
public:
    SDLImageException(const std::string& message) : SDLException(message) {}
};

// Generic interface for basic classes
class Window {
public:
    virtual ~Window() {
        SDL_DestroyRenderer(renderer_);
        SDL_DestroyWindow(window_);
        std::cout << "Window destroyed" << std::endl;
    }

    void create(const std::string& title, unsigned int width, unsigned int height) {
        window_ = SDL_CreateWindow(title.c_str(),
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            width, height, SDL_WINDOW_SHOWN);
        if (window_ == nullptr) {
            throw SDLException("Couldn't create window");
        }

        renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
        if (renderer_ == nullptr) {
            throw SDLException("Couldn't create renderer");
        }

        SDL_SetRenderDrawColor(renderer_, 0, 0, 0, SDL_ALPHA_OPAQUE);
        std::cout << "Window created" << std::endl;
    }

    void clear() {
        SDL_RenderClear(renderer_);
    }

    void display() {
        SDL_RenderPresent(renderer_);
    }

private:
    SDL_Window* window_{nullptr};
    SDL_Renderer* renderer_{nullptr};
};

class Application {
public:
    virtual void create() {}
    virtual void destroy() {}
    virtual void update() {}

    int run() {
        create();
        while (running_) {
            update();
        }

        destroy();
        return errorCode_;
    }

    void exit(int errorCode = 0) {
        std::cout << "Exit with code " << errorCode << std::endl;
        errorCode_ = errorCode;
        running_ = false;
    }

private:
    int errorCode_{0};
    bool running_{true};
};

class HelloSdlApp : public Application {
public:
    virtual void create() override {
        window_.create("Hello SDL", 640, 480);
    }

    virtual void destroy() override {
    }

    virtual void update() override {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                exit();
            }
        }

        window_.clear();
        window_.display();
    }

private:
    class SDLSystem {
        public:
            SDLSystem() {
                if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
                    throw SDLException("Couldn't start SDL");
                }
                std::cout << "SDL inited" << std::endl;
            }

            virtual ~SDLSystem() {
                SDL_Quit();
                std::cout << "SDL quitted" << std::endl;
            }
    };

    SDLSystem sdlSystem_;
    Window window_{};
};

int main() {
    HelloSdlApp app;
    return app.run();
}
