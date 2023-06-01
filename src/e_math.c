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
long double e_acos(double x) { return E_PI2 - e_asin(x); }

/*==============================================================================
                          3 long double asin(double x)
                              Arc sine computing
==============================================================================*/
long double e_asin(double x) {
  long double res = 0.0;
  if (x == 1.0 || x == -1.0) {  // boundary values duck tape:)
    res = x * E_PI2;
  } else if (-1.0 < x && x < 1.0) {
    int term_num = 0;
    long double term = x;  // first series member
    do {
      res += term;
      // next term of series:
      term_num++;
      term *= x * x * (2 * term_num - 1) / (2 * term_num) *
              (2 * term_num - 1) / (2 * term_num + 1);
    } while (term > PRECISION * 1E-6);
  } else {
    res = E_NAN;
  }
  return res;
}

/*==============================================================================
                          6 long double cos(double x)
                              Cosine computing
==============================================================================*/
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

/*==============================================================================
                          13 long double sin(double x)
                                Sine computing
==============================================================================*/
long double e_sin(double x) { return e_cos(E_PI2 - x); }

/*==============================================================================
                        15 long double tan(double x):
                            Tangent computing
==============================================================================*/
long double e_tan(double x) { return e_sin(x) / e_cos(x); }

/*==============================================================================
                              ADDITIONAL FUNCTIONS
==============================================================================*/
int isNAN(double x) { return x != x; }
int isINF(double x) { return (x == PLUS_8 || x == MINUS_8); }

// evgeny:
long double e_fmod(double x, double y) {
  long double result = 0.0;
  long double n = 0.0;
  if (y == 0) {
    result = E_NAN;
  } else {
    n = (x / y);
    if (n < 0) {
      n = e_ceil(n);
    } else {
      n = e_floor(n);
    }
  }
  result = x - n * y;
  return result;
}

long double e_ceil(double x) {
  long double result = x;
  if (x != x)
    result = E_NAN;
  else if (x == MINUS_8)
    result = MINUS_8;
  else if (x == PLUS_8)
    result = PLUS_8;
  else if (x > 0.0) {
    if (x < E_INT64_MAX - 1) result = (long long int)x + 1;
  } else if (x - (long long int)x == 0)
    result = x;
  else if (x < 0 && x > E_INT64_MIN)
    result = (long long int)result;
  return result;
}

long double e_floor(double x) {
  long double result = x;
  if (x != x)
    result = E_NAN;
  else if (x == MINUS_8)
    result = MINUS_8;
  else if (x == PLUS_8)
    result = PLUS_8;
  else {
    if (x < 0) {
      if (x > E_INT64_MIN + 1) result = (long long int)x - 1.0;
    } else if (x - (long long int)x == 0)
      result = x;
    else if (x > 0 && x < E_INT64_MAX)
      result = (long long int)result;
  }
  return result;
}
