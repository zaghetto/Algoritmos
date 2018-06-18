#include <stdio.h>
#include <stdlib.h>

// Abre o arquivo e mostrar as siglas dos partidos de cada candidato.

int main (int argc, char *argv[])
{
    FILE *fp;
    char c;

    if (argc!=2) {
        printf("Numero de parametros diferente de dois.\n");
        exit(1);
    }

    fp=fopen(argv[1], "r");

    if(fp==NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(2);
    }

    fscanf (fp, "%c", &c);

    int contpv = 0;

    int min = 10000, max = -1;

    int num[2], i = 1;

    while (!feof(fp)) {

        if (c == ';') contpv++;

        if (contpv == 17 && c!=';' && c!='\"'){
            //printf("%c", c);

            num[i] = c-'0';

            i--;
        }

        fscanf(fp, "%c", &c);

        if(c=='\n') {
            contpv = 0;
            i = 1;
            int partNum = num[1]*10 + num[0];
            printf("%d\n", partNum);
            printf("\n");
            if (partNum>max)
                max = partNum;
            else if(partNum<min)
                min = partNum;
        }
    }

    printf("MAX: %d \n", max);
    printf("MIN: %d \n", min);
    fclose(fp);

    return 0;
}


