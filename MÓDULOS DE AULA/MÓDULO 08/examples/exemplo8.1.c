#include <stdio.h>
#include <stdlib.h>
#define MAXL 3
#define MAXC 3

int main()
{
      float matriz[MAXL][MAXC];
      int i, j;

      for(i=0;i<=MAXL-1;i++) {
	   for(j=0;j<=MAXC-1;j++) {
            printf("Digite matriz[%d][%d]:",i,j);
            scanf("%f",&matriz[i][j]);
          }
      }


            for(i=0;i<=MAXL-1;i++) {
	   for(j=0;j<=MAXC-1;j++) {
            printf("%f\t", matriz[i][j]);
          }
        printf("\n");
      }


     return 0;
}
