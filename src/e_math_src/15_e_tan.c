/**
 * src/15_e_tan.c
 * (c) T. Enikeev
 * enikeev.tg@gmail.com
 *
 * @brief Tangent computing
 * @return The tan(x) value
 */

#include "../e_math.h"

long double e_tan(double x) { return e_sin(x) / e_cos(x); }

// ANOTHER WAYS (still doesn't work):
/*
#define BERNULLI                                                       \
  long double bernulli[12] = {1. / 6,       1. / 30,      1. / 42,     \
                              1. / 30,      5 / 66,       691 / 2730,  \
                              7 / 6,        3617 / 510,   43867 / 798, \
                              174611 / 330, 854513 / 138, 236364091 / 2730};

long double e_tan_mclrn(double x) {
  long double res = 0.0;
  if (isNAN(x) || isINF(x)) {  // nan a infinity value checking
    res = E_NAN;
  } else {
    if (x >= E_PI2) x = fmod(x, E_PI2) - E_PI2;
    if (x <= -E_PI2) x = fmod(x, E_PI2) + E_PI2;
    int i = 1;             // number of series member
    long double term = x;  // first series member
    BERNULLI;
    double pw;
    double factorial = 2.;
    do {
      res += term;
      // next term of series:
      i++;
      pw = pow(2., 2. * i);
      factorial *= (2. * i - 1.) * (2. * i);
      term = bernulli[i - 1] * pw * (pw - 1.) / factorial * pow(x, 2. * i - 1.);
    } while (PRECISION < term && term < 1E16);
  }
  return res;
}
*/
