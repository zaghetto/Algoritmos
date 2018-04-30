#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int *x[2], y0[2] = {0,1}, y1[2] = {2,3} ;

  x[0] = y0;
  x[1] = y1;

  printf("Conteudo de x[0] = y0: %d \n", x[0]);
  printf("Conteudo de x[1] = y1: %d \n", x[1]);
  printf("Endereço do primeiro elemento do vetor x: %d \n", &x[0]);
  printf("Endereço do segundo elemento do vetor x: %d \n", &x[1]);

printf("Conteudo de y0[0]: %d \n", *(x[0] + 0)); //y0[0]
  printf("Conteudo de y0[1]: %d \n", *(x[0] + 1)); //y0[1]
  printf("Endereço de y0[0]: %d \n", (x[0] + 0)); //&y0[0]
  printf("Endereço de y0[1]: %d \n", (x[0] + 1)); //&y0[1]

  printf("Conteudo de y1[0]: %d \n", *(x[1] + 0)); //y1[0]
  printf("Conteudo de y1[1]: %d \n", *(x[1] + 1)); //y1[1]
  printf("Endereço de y1[0]: %d \n", (x[1] + 0)); //&y1[0]
  printf("Endereço de y1[1]: %d \n", (x[1] + 1)); //&y1[1]


  return 0;
}
