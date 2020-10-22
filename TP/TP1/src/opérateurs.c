#include <stdio.h>

int main(){
	int a = 16;
	int b = 3;
	int sum = a + b;
	int mult = a*b;
	float div = a/b; // Même en déclarant un float on aura pas le bon résultat car a et b sont des int, il faudrait transtyper
	
	printf("somme : %hd, produit : %hd, division : %f", sum, mult, div);
	
	return 0;
}
