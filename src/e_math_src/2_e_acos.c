/**
* src/2_acos.c
* (c) T. Enikeev
* enikeev.tg@gmail.com
*
* @brief arc cosine computing
* @warning x argument must be in the range [-1, 1]
* @return an arccos(x) value
**/

#include "../e_math.h"

long double e_acos(double x) { return E_PI2 - e_asin(x); }
