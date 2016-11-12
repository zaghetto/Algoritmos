#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
	
	int laco = 0, n = 0;
	float a3, a2, a1, a0, x0, x1, e, xm, fx0, fx1, fxm;
	
	printf("\n a3: ");
		scanf("%f", &a3);
	printf("\n a2 : ");
		scanf("%f", &a2);
	printf("\n a1: ");
		scanf("%f", &a1);
	printf("\n a0: ");
		scanf("%f", &a0);
	printf("\n x0: ");
		scanf("%f", &x0);
	printf("\n x1: ");
		scanf("%f", &x1);
	printf("\n e: ");
		scanf("%f", &e);
					
	do{
		
		xm = (x0 + x1)/2.0;	
		fx0 = ((a3 * (pow(x0,3.0))) + (a2 * (pow(x0,2.0)))  + (a1 * x0) + a0);		
		fx1 = ((a3 * (pow(x1,3.0))) + (a2 * (pow(x1,2.0)))  + (a1 * x1) + a0);			
		fxm = ((a3 * (pow(xm,3.0))) + (a2 * (pow(xm,2.0)))  + (a1 * xm) + a0);		
			
		if ((fx0 < 0) && (fx1 > 0)){
			if (fxm > 0){
				x1 = xm;
			}else{
				x0 = xm;
			}
		} else{
			if (fxm > 0){
				x0 = xm;
			}else{
				x1 = xm;
			}
		}
			
	}while (fxm != 0 && fabs(x0-x1)>e );

	printf("Raiz: %f", xm);

	getchar ();
	return 0;
}
