/**
 * src/13_e_sin.c
 * (c) T. Enikeev
 * enikeev.tg@gmail.com
 *
 * @brief Sine computing
 * @return The sin(x) value
 */

#include "../e_math.h"

/*==============================================================================
                          13 long double sin(double x)
                                Sine computing
==============================================================================*/
long double e_sin(double x) { return e_cos(E_PI2 - x); }

// long double e_sin(double x) { 
//   return (x == x && e_fabs(x) != PLUS_8) ? e_cos(E_PI2 - x) : E_NAN;
// }

// ANOTHER WAYS:
// long double e_sin(double x) { return sin_cos_series(x, x, 1); }
