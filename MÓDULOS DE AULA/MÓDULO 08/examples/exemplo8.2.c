#include <stdio.h>
#include <stdlib.h>
#define MAX 15

int main()
{
int i, numero;

srand(2);
for(i=0;i<=MAX-1; i++){
        numero = rand()%10;
        printf("%d ", numero);
        printf("\n");

}
printf("\n");
return 0;
}
