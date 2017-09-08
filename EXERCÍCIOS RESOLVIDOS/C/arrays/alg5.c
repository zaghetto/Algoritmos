#include <stdio.h>

int main()
{
    int i, V, N[6] = {0};
    unsigned int P;
    int temp;

    for(i = 0; i < 5; i++){
        scanf("%d", &N[i]);
    }

    scanf("%d", &V);
    scanf("%d", &P);

    for(i = 0; i < 6; i++){
        printf("N[%d] = %d\n", i, N[i]);
    }

    for(i = 5; i > P; i--)
        N[i] = N[i - 1];

    N[P] = V;

    for(i = 0; i < 6; i++){
        printf("N[%d] = %d\n", i, N[i]);
    }

    return 0;
}
