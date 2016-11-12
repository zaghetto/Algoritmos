#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <time.h>

int main (){

    float n = 1.0, pi_atual = 0, pi_anterior=1000, e=0.001, termo;
    int sinal=1;
    double tempo;
    time_t inicio, fim;       

    time (&inicio);
    
	while (fabs(pi_anterior-pi_atual)>=e){
            
			pi_anterior = pi_atual;
			
			termo = (sinal*4)/n;
			
            pi_atual = pi_atual + termo;
            			
            n+=2;
            sinal = -sinal;  						
    }

    printf ("pi = %f\n", pi_atual);
    time (&fim);
    tempo = difftime(fim, inicio);
    printf ("Tempo: %.1lf\n", tempo);

system ("PAUSE");
return 0;

}
