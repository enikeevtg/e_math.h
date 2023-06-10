/**
 * src/3_asin.c
 * (c) T. Enikeev
 * enikeev.tg@gmail.com
 *
 * @brief Arc sine computing
 * @warning The x argument must be in the range [-1, 1]
 * @return The arcsin(x) value
 */

#include "../e_math.h"

long double e_asin(double x) {
  long double res = 0.0;
  if (x == 1.0 || x == -1.0) {  // boundary values duck tape:)
    res = x * E_PI2;
  } else if (-1.0 < x && x < 1.0) {
    int sign = (x >= 0 ? 1 : -1);  // sign of 'x'
    int term_num = 0;
    long double term = fabs(x);  // first series member
    do {
      res += term;
      // next term of series:
      term_num++;
      term *= x * x * (2 * term_num - 1) / (2 * term_num) * (2 * term_num - 1) /
              (2 * term_num + 1);
    } while (term > PRECISION);
    res *= sign;
  } else {
    res = E_NAN;
  }
  return res;
}
