/*
 * src/e_math.h
 * (c) T. Enikeev
 * enikeev.tg@gmail.com
 */

#ifndef SRC_TAGIR_E_MATH_H_
#define SRC_TAGIR_E_MATH_H_

#include <stdio.h>
#include <math.h>

#define E_PI 3.141592653589793238462643383280
#define E_PI2 1.570796326794896619231321691640
#define PRECISION 1E-11

long double e_acos(double x);  // 2
long double e_asin(double x);  // 3
long double e_cos(double x);  // 6
long double e_sin(double x);  // 13
long double e_tan(double x);  // 15

long double e_cos_alter(double x);  // 6
long double e_sin_alter(double x);  // 13
long double sin_cos_mclrn(double x, long double term, int rate);  // for 6 && 13

#endif  // SRC_TAGIR_E_MATH_H_
