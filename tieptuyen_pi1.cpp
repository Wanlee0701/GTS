//xap xi pi tiep tuyen
#include<stdio.h>
#include<math.h>
double f(double x){
	return tan(x/4) -1;
	}
double	f1(double x){
	return 0.25*1/pow(cos(x/4),2);
	} 
double f2(double x){
	return 0.5* (sin(x/4)/pow(cos(x/4),3));
}

int main(){
	/*B1:
	x = pi => f(x) = tan(x/4) - 1 = 0 
	f'(x) = 1/cos^2(x); f"(x) = (cosx^-2)' = -2cosx^-3.-sinx = 2cosx^3.sinx
	minf'(x).maxf'(x) > 0
	minf"(x).maxf"(x) > 0
	B2:
	f(3.2).f"(3.2) > 0
	Chon x = 3.2
	*/
	double xo = 3.2 ,e;
	printf("Nhap sai so: ");
	scanf("%lf",&e);
	double m1 = f1(3);
	//B4 Tim xap xi
	double x1= xo - f(xo)/f1(xo);
	double e0 = m1 * e;
	while (fabs(f(x1)) > e0){
		xo = x1;
		x1 = xo - f(xo)/f1(xo); 
		
	}
	printf("So dung cua pi: %.12lf",x1);
	
	/*double eo = m1*e;
	while(fabs(f(xo))>eo){
		xo = x1;
		x1 = xo - f(xo)/f1(xo);

		}
	printf("pi = %.12lf",x1);
	*/
	return 0;
}

