/**
 * src/6_e_cos.c
 * (c) T. Enikeev
 * enikeev.tg@gmail.com
 *
 * @brief Cosine computing
 * @return The cos(x) value
 */

#include "../e_math.h"

long double e_cos(double x) {
  x = e_fmod(x, 2 * E_PI);  // for big input value
  long double res = 0.0;
  if (isNAN(x) || isINF(x)) {  // nan a infinity value checking
    res = E_NAN;
  } else {
    int term_num = 0;  // number of series member
    int sign = 1;
    long double term = 1.0;  // first series member
    do {
      res += sign * term;
      // next term of series:
      sign = -sign;
      term_num++;
      term *= x * x / ((2 * term_num - 1) * (2 * term_num));
    } while (term > PRECISION);
  }
  return res;
}

// ANOTHER WAYS:
// long double e_cos(double x) { return sin_cos_series(x, 1.0, -1); }
