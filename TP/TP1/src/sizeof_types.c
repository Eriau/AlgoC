#include <stdio.h>

int main(){
	// char
	printf("char : %hd octets\n", sizeof(char));
	printf("unsigned char : %hd octets\n", sizeof(unsigned char));
	// short int
	printf("short int : %hd octets\n", sizeof(short int));
	printf("unsigned short int : %hd octets\n", sizeof(unsigned short int));
	// int
	printf("int : %hd octets\n", sizeof(int));
	printf("unsigned int : %hd octets\n", sizeof(unsigned int));
	// long
	printf("long : %hd octets\n", sizeof(long));
	printf("unsigned long : %hd octets\n", sizeof(unsigned long));
	// long long
	printf("long long int : %hd octets\n", sizeof(long long int));
	printf("unsigned long long int : %hd octets\n", sizeof(unsigned long long int));
	//float
	printf("float : %hd octets\n", sizeof(float));
	//double
	printf("double : %hd octets\n", sizeof(double));
	//long double
	printf("long double : %hd octets\n", sizeof(long double));
	return 0;
}
