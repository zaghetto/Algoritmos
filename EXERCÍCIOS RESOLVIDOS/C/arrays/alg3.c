#include <stdio.h>

int main(){

    unsigned short int i = 0, N[100] = {-1}, F[100] = {0};
    short int V;

    for(scanf("%hd", &V); V >= 0 && i < 100; scanf("%hd", &V), i++)
    {
        N[i] = V;
        F[V]++;
    }

    for(i = 0; i < 100; i++)
    {
        if(F[i] != 0)
            printf("Frequencia de %d = %d\n", i, F[i]);
    }

    return 0;
}
