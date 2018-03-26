#include <stdio.h>
#include <stdlib.h>

int main()
{
 int N, contador;

 printf("Digite o valor de N:");
 scanf("%d", &N);
 contador = 0;
 while(contador <= N) {
   printf("%d\n", contador);
   contador = contador + 1;
 }
 printf("%d\n", contador);

 return 0;
}
