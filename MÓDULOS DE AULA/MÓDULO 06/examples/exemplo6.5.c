#include <stdio.h>
#include <stdlib.h>

int main( )
{
int Npares = 0, Nimpares = 0, Numero;


do{
    printf("Digite um numero: ");
    scanf("%d", &Numero);
    if (Numero > 0)
    {
      if (Numero%2 == 0)
                   Npares++;
      else
                   Nimpares++;
    }

} while(Numero != -1);

printf("Numero de pares: %d \n", Npares);
printf("Numero de ímpares: %d \n", Nimpares);

return 0;
}

