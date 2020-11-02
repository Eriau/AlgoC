#include <stdio.h>
#include <string.h>

// FOR

int main(){
	short compter = 0;	
	while(compter <4){ // On s'assure que la taille du triangle rentrée est suffisante
		printf("Taille triangle ? (Plus que 4) : ");
		scanf("%hd", &compter);
	}
	for(unsigned char i=0; i<compter; i++){
		char aff[255] = "";	// On crée un tableau assez grand pour ne pas avoir de problème (255 un peu excessif)
		if ((i <=1) || (i == compter - 1)){ // Si on est à la première ou dernière ligne, on ne met que des *
			for(unsigned char l=0; l<=i; l++){
				strcat(aff, "*");	
			}	
			printf("%s\n", aff); 
		}
		else{
			for(unsigned char l=0; l<=i; l++){ // Sinon on regarde si on est en début ou fin de ligne, et on met des * ou des # selon notre position
				if ((l==0) || (l==i)){
					strcat(aff, "*");	
				}
				else{
					strcat(aff, "#");	
				}
			}
			printf("%s\n", aff);

		}
	}
	return 0;
}


//WHILE DO WHILE
/*
int main(){
	short compter = 0;
	int i = 0;
	int l = 0;	
	while(compter <4){
		printf("Taille triangle ? (Plus que 4) : ");
		scanf("%hd", &compter);
	}
	while(i<compter){
		char aff[255] = "";	
		if ((i <=1) || (i == compter - 1)){
			l = 0;
			while(l<=i){
				strcat(aff, "*");	
				l += 1;
			}	
			printf("%s\n", aff);
		}
		else{
			l = 0;
			while(l<=i){
				if ((l==0) || (l==i)){
					strcat(aff, "*");	
				}
				else{
					strcat(aff, "#");	
				}
				l += 1;
			}
			printf("%s\n", aff);
		}
		i += 1;
	}
	return 0;
}
*/