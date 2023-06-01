/*
 * src/e_math.h
 * (c) T. Enikeev
 * enikeev.tg@gmail.com
 */

#ifndef SRC_E_MATH_H_
#define SRC_E_MATH_H_

#include <math.h>
#include <stdio.h>

#define E_PI 3.141592653589793115997963468544185161590576171875
#define E_PI2 1.5707963267948965579989817342720925807952880859375
#define PRECISION 1E-7

#define PLUS_8 1.0 / 0.0
#define MINUS_8 -1.0 / 0.0
#define E_NAN 0.0 / 0.0

#define BERNULLI                                                       \
  long double bernulli[12] = {1. / 6,       1. / 30,      1. / 42,     \
                              1. / 30,      5 / 66,       691 / 2730,  \
                              7 / 6,        3617 / 510,   43867 / 798, \
                              174611 / 330, 854513 / 138, 236364091 / 2730};

long double e_sin(double x);  // 6
long double e_cos(double x);  // 13
long double e_tan(double x);  // 15
long double e_tan_mc(double x);  // It does not work!

long double sin_cos_series(double x, long double term, int rate);  // 6 && 13
int isNAN(double x);
int isINF(double x);

#endif  // SRC_E_MATH_H_
