/*
 * src/e_math/internal_math.h
 * (c) T. Enikeev
 * enikeev.tg@gmail.com
 */

#ifndef SRC_E_MATH_INTERNAL_MATH_H_
#define SRC_E_MATH_INTERNAL_MATH_H_

#include "../e_math.h"  // defines

int isNAN(double x);
int isINF(double x);
long double e_tan_mc(double x);  // It does not work!
long double sin_cos_mclrn(double x, long double term, int rate);

#endif  // SRC_E_MATH_INTERNAL_MATH_H_
