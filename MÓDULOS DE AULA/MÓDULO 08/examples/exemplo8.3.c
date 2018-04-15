#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

int main()
{
int i, numero;

srand(time(NULL));
for(i=0;i<=MAX-1; i++){
        numero = rand()%10;
        printf("%d ", numero);
        printf("\n");

}
printf("\n");
return 0;
}
