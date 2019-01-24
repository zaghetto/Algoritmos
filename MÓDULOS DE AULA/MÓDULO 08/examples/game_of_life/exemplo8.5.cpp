
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<playAPC/playapc.h>

#define N 50000
#define NINT 20

float geraAleat(int);

int main()
{
    float R1[N], R2[N], z0[N], z1[N];
    double histf[NINT], bins[NINT], intervalo;
    int hist[NINT];
    float numMax, numMin;
    int a = 22695477, b = 1, m = 1013904223;
    int i, j;

    // Gera R1
    R1[0] = 5;
    numMin = R1[0];
    for(i = 1; i < N; i++)
    {
        R1[i] = (a*(int)R1[i-1]+b)%m;

        if (R1[i] < numMin)
            numMin = R1[i];
    }

    for(i = 0; i < N; i++)
        R1[i] = R1[i]-numMin;

    numMax = R1[0];
    for(i = 0; i < N; i++)
        if (R1[i] > numMax)
            numMax = R1[i];

    for(i = 0; i < N; i++)
        R1[i] /= numMax;

    // Gera R2
    R2[0] = 23;
    numMin = R2[0];
    for(i = 1; i < N; i++)
    {
        R2[i] = (a*(int)R2[i-1]+b)%m;

        if (R2[i] < numMin)
            numMin = R2[i];
    }

    for(i = 0; i < N; i++)
        R2[i] = R2[i]-numMin;

    numMax = R2[0];
    for(i = 0; i < N; i++)
        if (R2[i] > numMax)
            numMax = R2[i];

    for(i = 0; i < N; i++)
        R2[i] = R2[i]/numMax;

    // Gera z0 e z1: distribuições normais padronizadas
    for(i = 0; i<N; i++)
    {
        z0[i] = sqrt(-2*log(R1[i]))*cos(2*M_PI*R2[i]);
        z1[i] = sqrt(-2*log(R1[i]))*sin(2*M_PI*R2[i]);
    }

    // Busca o máximo e o mínimo de z0
    numMin = z0[0];
    numMax = z0[0];
    for(i = 1; i < N; i++)
        if (z0[i] < numMin && fpclassify(z0[i]) != FP_INFINITE)
            numMin = z0[i];
        else if (z0[i] > numMax && fpclassify(z0[i]) != FP_INFINITE)
            numMax = z0[i];

    // Define o tamanho de cada intervalo
    intervalo = (numMax-numMin)/NINT;

    // Inicializa o histograma
    for(i = 0; i<NINT; i++)
        hist[0] = 0;

    // Para cada intervalo
    for(i = 0; i<NINT; i++)
    {
        // Armazena o centro do intervalo
        bins[i] = numMin + i*intervalo + intervalo/2;

        // Varre todo o vetor de dados e coloca cada valor no intervalo corresponsdente
        for(j = 0; j<N; j++)
        {
            if (z0[j]>= numMin + i*intervalo && z0[j] < numMin+ (i+1)*intervalo )
                hist[i]++;
        }
    }

    // Max value of histogram
    numMax = hist[0];
    for(i = 1; i < NINT; i++)
        if (hist[i] > numMax)
            numMax = hist[i];

    // Normalize histogram
    for(i = 0; i<NINT; i++)
        histf[i] = (float)hist[i]/numMax;

    // Max value of histogram
    numMax = fabs(bins[0]);
    for(i = 1; i < NINT; i++)
        if (fabs(bins[i]) > numMax)
            numMax = fabs(bins[i]);

    // Normalize histogram
    for(i = 0; i<NINT; i++)
        bins[i] = (float)bins[i]/numMax;

    for(i = 0; i<NINT; i++)
        printf("%.3f %lf\n", bins[i], histf[i]);


    Ponto p_back, p_face;
    int bar[NINT];
    int bar_line[NINT];
    j = -100;

    // Plot histrogram
    AbreJanela(600, 600, "Histogram");
    PintarFundo(255, 255, 255);
    MostraPlanoCartesiano(10);

    p_back.y = 0;
    p_face.y = 0;

    for(int i = 0; i < NINT; i++){

        p_back.x = j;
        p_face.x = j+1;

        j += 200/NINT;

        bar_line[i] = CriaRetangulo(200/NINT-2, histf[i]*90+1, p_back);
        Pintar(255, 0, 128);
        bar[i] = CriaRetangulo(200/NINT-4, histf[i]*90, p_face);
        Pintar(0, 0, 0);
    }

    Desenha();

    return 0;

}
