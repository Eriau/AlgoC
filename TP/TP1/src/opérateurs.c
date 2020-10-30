#include <stdio.h>

int main(){
	char a = 16;
	char b = 3;
	char sum = a + b;
	short int mult = a*b;
	float div = a/b;  // Comme a et b sont de types char, la division est de type char, même si on la stocke dans un float
	float divOk = (float)a/(float)b; // En transtypant a et b on a bien un résultat de type float que l'on stocke dans un float

	printf("somme : %hd, produit : %hd, division : %f, division correcte : %f", sum, mult, div, divOk);
	
	return 0;
}
