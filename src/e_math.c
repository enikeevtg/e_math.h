/*
 * src/e_math.c
 * (c) T. Enikeev
 * enikeev.tg@gmail.com
 */

#include "e_math.h"

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

long double e_fabs(double x) {
  long double result = 0;
  if (x == x) {
    if ((x > E_DBL_MIN) && (x < E_DBL_MAX)) {
      if (x < 0)
        result = -1.0 * x;
      else
        result = 1.0 * x;
    } else
      result = PLUS_8;
  } else
    result = E_NAN;
  return result;
}
