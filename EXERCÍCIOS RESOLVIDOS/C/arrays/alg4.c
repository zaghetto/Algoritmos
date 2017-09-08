#include <stdio.h>

int main()
{
    int i, j, N[5];
    unsigned int X;
    int temp;

    for(i = 0; i < 5; i++){
        scanf("%d", &N[i]);
    }

    scanf("%u", &X);

    for(i = 0; i < X; i++){
        temp = N[4];

        for(j = 4; j > 0; j--)
            N[j] = N[j - 1];

        N[0] = temp;
    }

    for(i = 0; i < 5; i++){
        printf("N[%d] = %d\n", i, N[i]);
    }

    return 0;
}
