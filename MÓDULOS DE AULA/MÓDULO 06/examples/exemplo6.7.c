#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
 float angulo, angrad, valcos, valserie, PI=3.14159265;
 float sinal, fatorial, termo;
 int i, j, Ntermos, Den;

 // Solicita o angulo em graus
 printf("Entre com o valor de um angulo:");
 scanf("%f", &angulo);

 // Converte para radianos
 angrad = angulo*PI/180;

  // Calcula o cosseno utilizando a função cos de math.h
 valcos = cos(angrad);

 /* Calcula o valor máximo do denominador,
 dada a quantidade de termos a serem adicionados */
 Ntermos = 3;
 Den = (Ntermos*2)-2;

 // Primeiro termo da serie
 valserie = 1;

 /* Dado que a cada interação o sinal
 do termo muda faz-se necessário declarar
 uma variável para controlar isso */
 sinal = 1;

   // Inicializa o valor do fatorial com 1
 fatorial = 1;

 // Calcula um novo termo a cada valor de denominador
 for(i = 2; i<=Den ; i+=2) {

       /* O calculo do novo termo depende de um fatorial.
       O fatorial do novo termo é calculado a partir do
       valor do fatorial anteriormente calculado.
       Isso aumenta a eficiente do programa
       */

       for (j = i-1; j<= i; j++){
          fatorial = fatorial*j;
       }

       // Inverte o dinal
       sinal = -sinal;

       // Calcula o novo termo
       termo = sinal*pow(angrad,i)/fatorial;

       // Acrescenta o novo termo ao somatório
       valserie = valserie + termo;
 }

  printf("\nFuncao cos(x): %f \n", valcos);
  printf("Calculado      : %f \n\n", valserie);

  return 0;
}
