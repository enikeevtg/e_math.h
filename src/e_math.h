/*
 * src/e_math.h
 * (c) T. Enikeev
 * enikeev.tg@gmail.com
 */

#ifndef SRC_E_MATH_H_
#define SRC_E_MATH_H_

#include "e_math/internal_math.h"

#include <math.h>
#include <stdio.h>

#define E_PI 3.141592653589793115997963468544185161590576171875
#define E_PI2 1.5707963267948965579989817342720925807952880859375
#define PRECISION 1E-8

#define PLUS_8 1.0 / 0.0
#define MINUS_8 -1.0 / 0.0
#define E_NAN 0.0 / 0.0

// #define e_isNan(x) __builtin_isnan(x)  // nan checking

long double e_acos(double x);  // 2
long double e_asin(double x);  // 3
long double e_sin(double x);   // 6
long double e_cos(double x);   // 13
long double e_tan(double x);   // 15

// evgeny:
#define E_INT64_MIN -9223372036854775807
#define E_INT64_MAX 9223372036854775807
#define E_DBL_MAX 1.7976931348623157E+308
#define E_DBL_MIN -1.7976931348623157E+308

long double e_fmod(double x, double y);
long double e_ceil(double x);
long double e_floor(double x);
long double e_fabs(double x);

#endif  // SRC_E_MATH_H_
