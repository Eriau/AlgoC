#include <stdio.h>

int main(){
	// char
	char c = 123; // {
    char *ptrChar = &c;
    printf("Adresse : %p  Valeur : %X \n", ptrChar, *ptrChar);
	// short int
	short int s = 2000;
    short int *ptrShort = &s;
	printf("Adresse : %p  Valeur : %X \n", ptrShort, *ptrShort);
	// int
	int i = 80000;
    int *ptrInt = (int *)&i;
	printf("Adresse : %p  Valeur : %X \n", ptrInt, *ptrInt);
	// long
	long int li = 4000000;
    int *ptrLong = (int *)&li;
	printf("Adresse : %p  Valeur : %X \n", ptrLong, *ptrLong);
	// long long
	long long int lli = -900;
    int *ptrLongLong = (int *)&lli;
	printf("Adresse : %p  Valeur : %X \n", ptrLongLong, *ptrLongLong);
	//float
	float f = 8.1;
    int *ptrFloat = (int*)&f;
	printf("Adresse : %p  Valeur : %X \n", ptrFloat, *ptrFloat);
	//double
    /*
	double d = 8.6;
    int *ptrDouble = (int*)&d;
    printf("Adresse : %p  Valeur : %X \n", ptrDouble, *ptrDouble);
	*/
	return 0;
}