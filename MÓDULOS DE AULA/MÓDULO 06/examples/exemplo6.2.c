#include <stdio.h>
#include <stdlib.h>

int main()
{
  float numero, soma = 0, media = 0;
  int N = 0;

  printf("Escreva uma nota:");
  scanf("%f", &numero);

  while(numero != -1) {
     N++;
     soma = soma + numero;
     printf("Escreva uma outra nota:");
     scanf("%f", &numero);
  }

    media = soma/N;
  printf("A media eh: %f \n", media);

  return 0;
}
