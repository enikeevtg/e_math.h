/*
 * src/main.c
 * (c) T. Enikeev
 * enikeev.tg@gmail.com
 */

#include <math.h>
#include <stdio.h>

#include "e_math.h"

int main() {
  double x = -0.5;
  // scanf("%lf", &x);

  // cos(x):
  printf("    cos(%lf) = %.6lf\n", x, cos(x));
  printf("e_cos(%lf) = %.6Lf\n\n", x, e_cos(x));

  // sin(x):
  printf("    sin(%lf) = %.6lf\n", x, sin(x));
  printf("e_sin(%lf) = %.6Lf\n\n", x, e_sin(x));

  // tan(x):
  printf("    tan(%lf) = %lf\n", x, tan(x));
  printf("e_tan(%lf) = %Lf\n\n", x, e_tan(x));

  // acos(x):
  printf("    acos(%lf) = %lf\n", x, acos(x));
  printf("e_acos(%lf) = %Lf\n\n", x, e_acos(x));

  // asin(x):
  printf("    asin(%lf) = %lf\n", x, asin(x));
  printf("e_asin(%lf) = %Lf\n", x, e_asin(x));

  return 0;
}
