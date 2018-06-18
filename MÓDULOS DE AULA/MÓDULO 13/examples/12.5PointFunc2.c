

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float funcao_pol(float);
float funcao_ln (float);
float funcao_sen(float);

float fun (float,   float (  *)(float)  );

typedef float (*Func)(float);

int main(){

	Func funcoes [3] = {funcao_pol, funcao_ln, funcao_sen};
	int n = 0, num_func;
	float e,x0,x1,xm, fx0, fx1, fxm;

	printf("Selecione e funcao:");
	scanf("%d", &num_func);

	printf("\n x0: ");
	scanf("%f", &x0);
	printf("\n x1: ");
	scanf("%f", &x1);
	printf("\n e: ");
	scanf("%f", &e);

	do{

	xm = (x0 + x1)/2.0;

	fx0 = fun(x0, funcoes[num_func]);
	fx1 = fun(x1, funcoes[num_func]);
	fxm = fun(xm, funcoes[num_func]);

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

return 0;

}

float funcao_pol(float x){

	float fx;
	static float a3, a2, a1, a0;
	static int set = 0;

	if(set==0){
		printf("\n Funcao polinomial : \n");
		printf("\n a3: ");
		scanf("%f", &a3);
		printf("\n a2 : ");
		scanf("%f", &a2);
		printf("\n a1: ");
		scanf("%f", &a1);
		printf("\n a0: ");
		scanf("%f", &a0);
		printf("\n");
	}

	fx = ((a3 * (pow(x,3.0))) + (a2 * (pow(x,2.0)))  + (a1 * x) + a0);

	set = 1;

	return fx;
}


float funcao_ln (float x){

	float fx;

	fx = x + log(x);

	return fx;

}

float funcao_sen(float x){

	float fx;

	fx = 5-x-5*sin(x);

	return fx;

}

float fun (float x,   float (*funcao)(float)  ) {


  return funcao(x);


}
