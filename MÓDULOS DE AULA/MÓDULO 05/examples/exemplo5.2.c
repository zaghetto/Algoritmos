// Alexandre Zaghetto
// zaghetto@unb.br
// University of Brasília
// Department of Computer Science

#include <stdio.h>
#include <stdlib.h>

int main(){

    char nome[50];

    printf("Digite seu nome: ");

    scanf("%[^\n]", nome);

    printf("O nome digitado foi: %s \n", nome);

    return 0;
}
