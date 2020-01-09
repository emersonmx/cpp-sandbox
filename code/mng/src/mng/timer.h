#ifndef MNG_TIMER_H
#define MNG_TIMER_H

#include <stdint.h>

namespace mng {
namespace timer {

double getTicksInSeconds(void);
uint32_t getTicksInMilliseconds(void);

} /* namespace timer */
} /* namespace mng */

#endif /* MNG_TIMER_H */
