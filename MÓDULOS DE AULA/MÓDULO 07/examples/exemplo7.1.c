
#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int main()
{
float media = 0, valores[MAX];
int i, conta = 0;

for(i=0;i<=MAX-1; i++){
 printf("Escreva um valor:");
 scanf("%f", &valores[i]);
 media = media + valores[i];
}

media = media/MAX;
printf("A media eh: %.2f \n\n", media);

for(i=0;i<=MAX-1; i++)
 if(valores[i] > media) conta++;

printf("Acima de %.2f: %d \n\n", media, conta);

return 0;

}
