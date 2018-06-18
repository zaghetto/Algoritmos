#include <stdio.h>
#include <stdlib.h>

// Ponteiro para função

int pega_result(int, int, int (* )(int, int));
int max(int, int);
int min(int, int);
int soma(int, int);


int main (int argc, char *argv[])
{
    int result, x1 = 10, x2 = 11;

    result = pega_result(x1, x2, &max);

    printf("O maximo entre %d e %d ‚ %d.\n",x1, x2, result);

    result = pega_result(x1, x2, &min);

    printf("O minimo de %d e %d ‚ %d.\n",x1, x2, result);

    result = pega_result(x1, x2, &soma);

    printf("A soma de %d com %d ‚ %d.\n",x1, x2, result);

    return 0;
}

int pega_result(int a, int b, int (*compare)(int , int ))
     {
       return compare(a, b);  // Chama a função passada
     }

int max(int a, int b)
     {
       printf("Em max:\n");
       return (a > b) ? a: b;
     }

int min(int a, int b)
    {
      printf("Em min:\n");
      return (a < b) ? a: b;
    }

int soma(int a, int b)
    {
      printf("Em soma:\n");
      return a+b;
    }
