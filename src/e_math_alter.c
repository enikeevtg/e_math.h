/*
 * src/e_math.c
 * (c) T. Enikeev
 * enikeev.tg@gmail.com
 */

#include "e_math_alter.h"

/*==============================================================================
                          6 long double cos(double x)
                              Cosine computing
==============================================================================*/
long double e_cos(double x) { return sin_cos_series(x, 1.0, -1); }

/*==============================================================================
                          13 long double sin(double x)
                                Sine computing
==============================================================================*/
long double e_sin(double x) { return sin_cos_series(x, x, 1); }

/*==============================================================================
                        15 long double tan(double x):
                            Tangent computing
==============================================================================*/
long double e_tan(double x) { return e_sin(x) / e_cos(x); }

// e_tan(x) with output 'inf':
// long double e_tan(double x) {
//   long double res = 0;
//   long double sine = e_sin(x);
//   long double cosine = e_cos(x);
//   if (fabs(cosine) < PRECISION) {
//     res = sine * PLUS_8;  // cause sin is 1 or -1, when cos is 0
//   } else {
//     res = sine / cosine; printf("cos != 0\n");
//   }
//   return res;
// }

/*==============================================================================
          Maclaurin's series for e_cos() and e_sin() functions
            'x' is argument
            'term' is first series member
            'rateis' a difference between sine and cosine
==============================================================================*/
long double sin_cos_series(double x, long double term, int rate) {
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
    return res;
  }
}

/*==============================================================================
                          15 long double tan(double x):
                    Tangent computing with Maclaurin series
                                It does not work!
==============================================================================*/
long double e_tan_mc(double x) {
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

/*==============================================================================
                          ADDITIONAL FUNCTIONS
==============================================================================*/
int isNAN(double x) { return x != x; }
int isINF(double x) { return (x == PLUS_8 || x == MINUS_8); }
