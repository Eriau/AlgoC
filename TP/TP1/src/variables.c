#include <stdio.h>

int main(){
	// char
	char c = 123; // {
	char c_deux = -120; // ê
	printf("char : %c \n", c_deux);
	printf("unsigned char : %c\n", c);
	// short int
	short int s = 2000;
	unsigned short int s_deux = -1000;
	printf("short int : %i\n", s_deux);
	printf("unsigned short int : %u\n", s);
	// int
	int i = 80000;
	int i_deux = -59000;
	printf("int : %d\n", i_deux);
	printf("unsigned int : %ud\n", i);
	// long
	long int li = 4000000;
	unsigned long int li_deux = -2049519;
	printf("long : %li\n", li);
	printf("unsigned long : %ld\n", li_deux);
	// long long
	long long int lli = -9000000000000000000;
	unsigned long long int lli_deux = 18000000000000000000; //Warning sur le type je ne sais pas pourquoi
	printf("long long int : %lli\n", lli);
	printf("unsigned long long int : %llu\n", lli_deux);
	//float
	float f = 8.1;
	printf("float : %f\n", f);
	//double
	double d = 8.6;
	printf("double : %lf\n", d);
	//long double
	//long double ld = 94.6; // Windows ne supporte pas les types avec 128 bits il me semble.
	//printf("long double : %Lf\n", ld);
	return 0;
}

