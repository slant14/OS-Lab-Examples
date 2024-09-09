#include <stdio.h>
#include <limits.h>
#include <float.h> 
// For using FLT_MAX and DBL_MAX including "floats.h" is mandatory since "limits.h" doesn't implement them
// For more info, please take a look at: https://en.cppreference.com/w/c/types/limits

int main() {
  // values are assigned randomly))
  int a = 1;
  unsigned short int b = 2;
  signed long int c = 3;
  float d = 4.0f;
  double e = 5.0;

  printf("a = %d, max int = %d\n", a, INT_MAX);
  printf("b = %d, max unsigned short int = %d\n", b, USHRT_MAX);
  printf("c = %ld, max signed long int = %ld\n", c, LONG_MAX);
  printf("d = %f, max float = %f\n", d, FLT_MAX);
  printf("e = %f, max double = %f\n", e, DBL_MAX);
}

