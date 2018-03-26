#include <stdio.h>
#include <stdlib.h>

int main()
{
  int N, maior, menor;

  printf("Digite um numero:");
  scanf("%d", &N);
  maior = N;
  menor = N;

  while(N != -1) {
     if (N < menor) {
        menor = N;
     } else if (N > maior) {
        maior = N;
     }
     printf("Digite outro numero:");
     scanf("%d", &N);
  }
  printf("Maior: %d \n", maior);
  printf("Menor: %d \n", menor);

  return 0;
}
