#include <stdio.h>

int main(){
	// char
	char c = 123; // {
    char *ptrChar = &c;
    printf("Adresse : %p  Valeur : %c \n", ptrChar, *ptrChar);
    *ptrChar = 121;
	printf("Adresse : %p  Valeur : %c \n", ptrChar, c); // On affiche toujours le contenu de c mais celui-ci est différent alors que l'on a seulement modifié le pointeur.
	// short int
	short int s = 2000;
    short int *ptrShort = &s;
	printf("Adresse : %p  Valeur : %hd \n", ptrShort, *ptrShort);
	// int
	int i = 80000;
    int *ptrInt = &i;
	printf("Adresse : %p  Valeur : %i \n", ptrInt, *ptrInt);
	// long
	long int li = 4000000;
    long int *ptrLong = &li;
	printf("Adresse : %p  Valeur : %li \n", ptrLong, *ptrLong);
	// long long
	long long int lli = -900;
    long long int *ptrLongLong = &lli;
	printf("Adresse : %p  Valeur : %lli \n", ptrLongLong, *ptrLongLong);
	//float
	float f = 8.1;
    float *ptrFloat = &f;
	printf("Adresse : %p  Valeur : %f \n", ptrFloat, *ptrFloat);
	//double
	double d = 8.6;
    double *ptrDouble = &d;
	printf("Adresse : %p  Valeur : %lf \n", ptrDouble, *ptrDouble);
	//long double // Windows ne supporte pas les types avec autant de bits il me semble.
	//long double ld = 945.6;
    //long double *ptrLongDouble = &ld;
	//printf("Adresse : %p  Valeur : %Lg \n", ptrLongDouble, *ptrLongDouble);

	return 0;
}

