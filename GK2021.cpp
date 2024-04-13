#include<stdio.h>
#include<math.h>
/* fx = 21x^5 - 12x^4 + 3x^2 - 15
f'x = 105x^4 - 48x^3 + 6x
f''x = 420x^3 - 144x^2 + 6 
KLP (1;2)
f'(x) > 0 voi (1,2)
f''(x) > 0 voi (1,2)
Chon x0 = 2 do f(x0)f''(x) >0*/
	double f(double x){
		return 21 * (pow(x,5)) - 12 * pow(x,4) + 3*pow(x,2) -15;
	}
	double f1(double x){
		return 105*pow(x,4) - 48*pow(x,3)+6*x;
	}
int main(){
	float m1, e, x0 = 2;
	printf("Nhap sai so: "); scanf("%f",&e);
	m1 = f1(2);
	float e0= e*m1;
	float x1 = x0 - f(x0)/f1(x0);
	while (fabs(f(x1))>e0){
		x0 = x1;
		x1 = x0 - f(x0)/f1(x0);
	}
	printf("Nghiem dung cua pt:%f ",x1);
}
