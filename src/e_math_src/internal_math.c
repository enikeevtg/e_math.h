/*
 * src/internal_math.c
 * (c) T. Enikeev
 * enikeev.tg@gmail.com
 */

#include "../internal_mathfuncs.h"

/*==============================================================================
                              Checking functions
==============================================================================*/
int e_isNAN(double x) { return x != x; }
int e_isINF(double x) { return (x == PLUS_8 || x == MINUS_8); }

/*==============================================================================
          Maclaurin's series for e_cos() and e_sin() functions
            'x' is argument
            'term' is first series member
            'rateis' a difference between sine and cosine
==============================================================================*/
long double sin_cos_mclrn(double x, long double term, int rate) {
  long double res = 0.0;
  if (isINF(x) || isNAN(x)) {
    res = E_NAN;
  } else {
    int term_num = 0;  // number of series member
    int sign = 1;
    do {
      res += sign * term;
      // next term of series:
      sign = -sign;
      term_num++;
      term *= x * x / (2 * term_num * (2 * term_num + rate));
    } while (term > PRECISION / 1000.0);
  }
  return res;
}
