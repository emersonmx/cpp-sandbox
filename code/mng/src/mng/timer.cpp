#include <mng/timer.h>

#include <SDL_timer.h>

namespace mng {
namespace timer {

double getTicksInSeconds(void)
{
    return SDL_GetPerformanceCounter()
        / static_cast<double>(SDL_GetPerformanceFrequency());
}

uint32_t getTicksInMilliseconds(void)
{
    return getTicksInSeconds() * 1000;
}

} /* namespace timer */
} /* namespace mng */
