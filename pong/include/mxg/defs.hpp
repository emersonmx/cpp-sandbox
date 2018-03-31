#ifndef MXG_DEFS_HPP_
#define MXG_DEFS_HPP_

namespace mxg {

#if REAL_T_IS_DOUBLE
using real_t = double;
#else
using real_t = float;
#endif

} /* namespace mxg */
#endif /* MXG_DEFS_HPP_ */
