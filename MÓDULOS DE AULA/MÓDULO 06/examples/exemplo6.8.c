#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
 float angulo, angrad, valcos, valserie;
 float PI=3.14159265;
 float sinal, fatorial, termo, erro, precisao = 0.0001;
 int i, j;

 // Solicita o angulo em graus
 printf("Entre com o valor de um angulo:");
 scanf("%f", &angulo);
 // Converte para radianos
 angrad = angulo*PI/180;
 printf("Angulo em rad: %f \n", angrad);

 // Calcula o cosseno utilizando a função cos de math.h
 valcos = cos(angrad);

 // Primeiro termo da serie
 valserie = 1;

 /* Dado que a cada interação o sinal
 do termo muda faz-se necessário declarar
 uma variável para controlar isso */
 sinal = 1;

 // Inicializa o valor do fatorial com 1
 fatorial = 1;

 // Calcula um novo termo a cada valor de denominador
 i = 2;

 // Inicializa termo com o valor para entrar no laço
 termo = 1;
 while( fabs(termo) >= precisao) {

       /* O cálculo do novo termo depende de um fatorial.
       O fatorial do novo termo é calculado a partir do
       valor do fatorial anteriormente calculado.
       Isso aumenta a eficiente do programa. */

       for (j = i-1; j<= i; j++) fatorial = fatorial*j;


       // Inverte o sinal
       sinal = -sinal;

       // Calcula o novo termo
       termo = sinal*pow(angrad,i)/fatorial;
       printf("termo: %f \n", termo);

       // Acrescenta o novo termo ao somatório
       valserie = valserie + termo;
       printf("serie: %f \n", valserie);

       /* Incrementa i para calculo do denominador
        e potência de x */
       i +=2;

 }

  // Mostra os resultados na tela do computador
 printf("\nFuncao cos(x)      : %f \n", valcos);
 printf("Calculado pela serie : %f \n\n", valserie);

 return 0;

 }
