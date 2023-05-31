/*
 * src/e_math.c
 * (c) T. Enikeev
 * enikeev.tg@gmail.com
 */

#include "e_math.h"

/*==============================================================================
                          2 long double acos(double x):
                              Arc cosine computing
==============================================================================*/
long double e_acos(double x) {
  return E_PI2 - e_asin(x);
}

/*==============================================================================
                          3 long double asin(double x)
                              Arc sine computing
==============================================================================*/
long double e_asin(double x) {
  if (-1.0 <= x && x <= 1.0) {
    long double res = 0;
    double term_num = 0.0;
    long double term = x;  // first series member
    do {
      res += term;
      // next term of series:
      term_num++;
      term *= x * x * (2 * term_num - 1) / (2 * term_num) * (2 * (term_num - 1) + 1) / (2 * term_num + 1);
    } while (term > PRECISION);
    return res;
  }
}

/*==============================================================================
                          6 long double cos(double x)
                              Cosine computing
==============================================================================*/
long double e_cos(double x) {
  long double res = 0;
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
  return res;
}

long double e_cos_alter(double x) {
  return sin_cos_series(x, 1.0, -1);
}

/*==============================================================================
                          13 long double sin(double x)
                                Sine computing
==============================================================================*/
long double e_sin(double x) {
  long double res = 0;
  int term_num = 0;  // number of series member
  int sign = 1;
  long double term = x;  // first series member
  do {
    res += sign * term;
    // next term of series:
    sign = -sign;
    term_num++;
    term *= x * x / ((2 * term_num) * (2 * term_num + 1));
  } while (term > PRECISION);
  return res;
}

long double e_sin_alter(double x) {
  return sin_cos_series(x, x, 1);
}

/*==============================================================================
                        15 long double tan(double x):
                            Tangent computing
==============================================================================*/
long double e_tan(double x) {
  return e_sin(x) / e_cos(x);
}

/*==============================================================================
          Maclaurin's series for e_cos() and e_sin() functions
            'x' is argument
            'term' is first series member
            'rateis' a difference between sine and cosine
==============================================================================*/
long double sin_cos_mclrn(double x, long double term, int rate) {
  long double res = 0;
  int term_num = 0;  // number of series member
  int sign = 1;
  do {
    res += sign * term;
    // next term of series:
    sign = -sign;
    term_num++;
    term *= x * x / (2 * term_num * (2 * term_num + rate));
  } while (term > PRECISION);
  return res;
}
