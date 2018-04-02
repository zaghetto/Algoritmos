#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
 int N, i;
 double tempo;
 time_t inicio, fim;

  printf("Digite o valor de N:");
 scanf("%d", &N);

 time(&inicio);
 for(i = 0; i<=N; i++) {
   printf("%d\n", i);
}
 time(&fim);
 tempo = difftime(fim, inicio);

 printf("Tempo total: %.1lf segundos", tempo);

 return 0;
}
