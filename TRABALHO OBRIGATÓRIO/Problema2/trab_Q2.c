#include <stdio.h>
#include <stdlib.h>

// Abre o arquivo e mostrar as siglas dos partidos de cada candidato.
// Além disso, mostra o número da menor e da maior sigla.

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

     // Faz a leitura do cabeçalho, descartando a informação
     // Lê até encontrar a primeira quebra de linha.
     fscanf (fp, "%c", &c);
     while (c != '\n') {
            fscanf (fp, "%c", &c);
     }

    // Conta a quantidade de ponto e vírgulas
    int contpv = 0;

    int min = 10000, max = -1;

    // Utilizado para converter string de dois caracteres em um inteiro de dois dígitos: sigla do partido
    int sigla[2], i = 1;

    // Faz a leitura do primeiro caracter
    fscanf (fp, "%c", &c);

    while (!feof(fp)) {

        // Caso encontre um ponto-e-vírgula, conta.
        if (c == ';') contpv++;

        // Após ler o vigésimo-sétimo ponto e virgula
        if (contpv == 27 && c!=';' && c!='\"'){

            // Realiza um deslocamento baseado na tabela ASCII
            sigla[i] = c-'0';

            i--;
        }

        // Ao se chegar no final do registro de um candidato...
        if(c == '\n') {

            //...o contador de pontos-e-vírgulas é reiniciado.
            contpv = 0;

            // Inicia-se também o índice para o vetor que armazena os dois caracteres do número do partido
            i = 1;

            // Converte-se a sigla do partido em um número inteiro
            int partNum = sigla[1]*10 + sigla[0];

            // Se a última leitura não tiver gerado um final de arquivo mostra o número do partido
            if(!feof(fp))
                printf("%d\n", partNum);

            // Verifica qual é o maior número de partido
            if (partNum>max)
                max = partNum;
            else if(partNum<min)
                min = partNum;
        }

        // Faz a leitura do próximo caracter
        fscanf(fp, "%c", &c);

    }

    printf("MAX: %d \n", max);
    printf("MIN: %d \n", min);

    fclose(fp);

    return 0;
}


