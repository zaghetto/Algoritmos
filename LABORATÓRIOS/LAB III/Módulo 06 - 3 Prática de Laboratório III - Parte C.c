#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main ()
{
	float comp, larg, e;
	float a, b;
	float x1, x2, xm, fx1, fx2, fxm;

	printf("Comprimento: ");
    scanf("%f", &comp);
	printf("Largura: ");
    scanf("%f", &larg);
	printf("a: ");
    scanf("%f", &a);
	printf("b: ");
    scanf("%f", &b);
	printf("\nPrecisao: ");
    scanf("%f", &e);

	do{
		x1 = a + (b - a)/3.0;
		x2 = b - ((b - a)/3.0);
		fx1 = (comp - 2.0*x1) * (larg - 2.0*x1) * x1;
		fx2 = (comp - 2.0*x2) * (larg - 2.0*x2) * x2;

		if (fx2 >= fx1)
			a = x1;
		else
			b = x2;

	}while (fabs(b-a) > e);

	xm = (a + b)/2.0;
	fxm = (comp - 2.0*xm) * (larg - 2.0*xm) * xm;

	printf("\nVolume maximo: %f\n", fxm);
	printf("\nAltura maxima: %f\n", xm);

	system("PAUSE");
	return 0;
}
