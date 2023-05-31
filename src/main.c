/*
 * src/main.c
 * (c) T. Enikeev
 * enikeev.tg@gmail.com
 */

#include <stdio.h>
#include <math.h>

#include "e_math.h"

int main() {
  double x;
  scanf("%lf", &x);

  // cos(x):
  printf("cos(%lf) = %lf\n", x, cos(x));
  printf("e_cos(%lf) = %Lf\n\n", x, e_cos(x));
  
  // sin(x):
  printf("sin(%lf) = %lf\n", x, sin(x));
  printf("e_sin(%lf) = %Lf\n\n", x, e_sin(x));

  // tan(x):
  printf("tan(%lf) = %lf\n", x, tan(x));
  printf("e_tan(%lf) = %Lf\n\n", x, e_tan(x));

  // acos(x):
  printf("acos(%lf) = %lf\n", x, acos(x));
  printf("e_acos(%lf) = %Lf\n\n", x, e_acos(x));

  // asin(x):
  printf("asin(%lf) = %lf\n", x, asin(x));
  printf("e_asin(%lf) = %Lf\n", x, e_asin(x));

  return 0;
}
