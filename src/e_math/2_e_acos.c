/*
 * src/2_acos.c
 * (c) T. Enikeev
 * enikeev.tg@gmail.com
 */

#include "../e_math.h"

/*==============================================================================
                          2 long double acos(double x):
                              Arc cosine computing
==============================================================================*/
long double e_acos(double x) { return E_PI2 - e_asin(x); }
