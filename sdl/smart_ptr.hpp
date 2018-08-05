#ifndef SDL2_SMART_PTR_HPP_
#define SDL2_SMART_PTR_HPP_

namespace sdl2 {
    struct SDL_Deleter {
        void operator()(SDL_Surface* surface) {
            SDL_FreeSurface(surface);
            std::cout << "SDL_FreeSurface()" << std::endl;
        }
        void operator()(SDL_Texture* texture) {
            SDL_DestroyTexture(texture);
            std::cout << "SDL_DestroyTexture()" << std::endl;
        }
        void operator()(SDL_Renderer* renderer) {
            SDL_DestroyRenderer(renderer);
            std::cout << "SDL_DestroyRenderer()" << std::endl;
        }
        void operator()(SDL_Window* window) {
            SDL_DestroyWindow(window);
            std::cout << "SDL_DestroyWindow()" << std::endl;
        }
        void operator()(SDL_RWops* rwops) {
            SDL_RWclose(rwops);
            std::cout << "SDL_RWclose()" << std::endl;
        }
    };

    using SurfacePtr = std::unique_ptr<SDL_Surface, SDL_Deleter>;
    using TexturePtr = std::unique_ptr<SDL_Texture, SDL_Deleter>;
    using RendererPtr = std::unique_ptr<SDL_Renderer, SDL_Deleter>;
    using WindowPtr = std::unique_ptr<SDL_Window, SDL_Deleter>;
    using RWopsPtr = std::unique_ptr<SDL_RWops, SDL_Deleter>;
}
#endif /* SDL2_SMART_PTR_HPP_ */
