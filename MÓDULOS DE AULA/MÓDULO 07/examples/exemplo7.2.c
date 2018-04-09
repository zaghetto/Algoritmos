#include <stdio.h>
#include <stdlib.h>

int main() {

  char a;

  printf("Tabela ASCII: \n\n");

  for(a='a'; a<=101; a++)
       printf("%d: Caracter %c\n\n", a, a);

  return 0;

}
