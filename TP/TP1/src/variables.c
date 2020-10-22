#include <stdio.h>

int main(){

	char c = "a";
	short s = 10;
	int i = 12;
	long int li = 50;
	long long int lli = 84;
	float f = 8.1;
	double d = 8.6;
	long double ld = 94.6;

	printf("char : %c, short : %hd, int : %d, long int : %ld, long long int : %lld, float : %f, double : %lf, long double : %llf", c, s, i, li, lli, f, d, ld);

	return 0;
}
