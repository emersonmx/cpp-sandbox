#ifndef MNG_MAIN_LOOP_H
#define MNG_MAIN_LOOP_H

#include <SDL.h>

namespace mng {

class Engine;

class MainLoop {
public:
    virtual void processEvents(SDL_Event& event) = 0;
    virtual void fixedUpdate(double delta) = 0;
    virtual void update(double delta) = 0;
    virtual void render() = 0;
};

class DefaultMainLoop : public MainLoop {
public:
    DefaultMainLoop(Engine& engine);

    void processEvents(SDL_Event& event) override;
    void fixedUpdate(double delta) override;
    void update(double delta) override;
    void render() override;

protected:
    Engine* engine_;
};

} /* namespace mng */

#endif /* MNG_MAIN_LOOP_H */
