
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int N, N1, N2;
  float Soma2;

  N = 1000;
  while(N <= 9999) {

     N1 = N/100;
     N2 = N-(100*N1);

     Soma2 = pow(N1+N2, 2);

          if (Soma2 == N) {
          printf("N1: %d \n", N1);
          printf("N2: %d \n", N2);
          printf("Soma2: %.0f \n", Soma2);
     }

     N++;
  }

  return 0;
}

