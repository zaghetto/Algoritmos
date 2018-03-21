// Alexandre Zaghetto
// zaghetto@unb.br
// University of Brasília
// Department of Computer Science

#include <stdio.h>
#include <stdlib.h>

int main()
{
 float operando1, operando2, resultado;
 int operacao;

 printf("Entre com o primeiro operando:");
 scanf("%f", &operando1);
 printf("Entre com o segundo operando:");
 scanf("%f", &operando2);
 printf("*****************\n");
 printf("Menu\n");
 printf("*****************\n");
 printf("1 - Soma\n");
 printf("2 - Subtração\n");
 printf("3 - Divisão\n");
 printf("4 - Multiplicação\n");
 printf("*****************\n");
 printf("Entre com a opcao:");
 scanf("%d", &operacao);

 switch (operacao) {
        case 1:
             resultado = operando1 + operando2;
             printf("O resultado da soma eh: %f \n", resultado);
             break;
        case 2:
             resultado = operando1 - operando2;
             printf("O resultado da subtração eh: %f \n", resultado);
             break;
        case 3:
             resultado = operando1 / operando2;
             printf("O resultado da divisão eh: %f \n", resultado);
             break;
        case 4:
             resultado = operando1 * operando2;
             printf("O resultado da multiplicação eh: %f \n", resultado);
             break;
        default:
             printf("Operação inválida!");
 }

 return 0;

}
