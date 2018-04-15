#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5

int main()
{
int i, j, valores[MAX][MAX];

// Inicia o gerador de números pseudo-aleatórios
srand(time(NULL));

// Preenche a matriz
for(i=0;i<=MAX-1; i++)
   for(j=0;j<=MAX-1; j++)
       valores[i][j] = rand() % 10;


       // Mostra a matriz
for(i=0;i<=MAX-1; i++){
   for(j=0;j<=MAX-1; j++){
       printf("%d \t",valores[i][j]);
   }
   printf("\n");
}
   printf("\n\n");

// Mostra a diagonal principal
for(i=0;i<=MAX-1; i++){
        printf("%d \t",valores[i][i]);
}
   printf("\n");


return 0;
}
