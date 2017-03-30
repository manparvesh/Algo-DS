#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int t, iter;
	double a, b, c, x;
	scanf("%d", &t);
	while(t--){
		scanf("%lf %lf %lf", &a, &b, &c);
		x = c / a;
		iter = 100;
		while(iter--){
			x -= (a * x + b * sin(x) - c) / (a + b * cos(x));
		}
		printf("%lf\n", x);
	}
	return 0;
}