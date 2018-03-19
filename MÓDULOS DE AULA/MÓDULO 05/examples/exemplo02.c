#include <stdio.h>
#include <stdlib.h>

int main()
{
    float valor;
    char presente;

    printf("Informe o valor da mercadoria:");
    scanf("%f", &valor);
    getchar();
    printf("Deverá ser embrulhada para presente?");
    scanf("%c", &presente);

    if (presente == 'S' || presente == 's') {
    	valor = valor + 1.50;
    }

    printf("Total a pagar: %f",valor);

    return 0;
}


