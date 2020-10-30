#include <stdio.h>

#define M_PI 3.14159265358979323846


typedef struct Cercle{
	float aire;
	float perim;
}Cercle_t;

Cercle_t cercle(float rayon, Cercle_t infoCercle);

int main(){
	Cercle_t infoCercle;
	float rayon;
	printf("Entrez un rayon :  ");
	scanf("%f", &rayon);
	infoCercle = cercle(rayon, infoCercle);
	printf("Aire : %f et Perim : %f", infoCercle.aire, infoCercle.perim); 
	return 0;
}

Cercle_t cercle(float rayon, Cercle_t infoCercle){
	infoCercle.aire = M_PI*rayon*rayon;
	infoCercle.perim = 2*M_PI*rayon;
	return(infoCercle);
}