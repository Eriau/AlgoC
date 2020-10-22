#include <stdio.h>
#include <string.h>

// FOR

/*
int main(){
	short compter = 0;	
	while(compter <4){
		printf("Taille triangle ? (Plus que 4) : ");
		scanf("%hd", &compter);
	}
	for(int i=0; i<compter; i++){
		char aff[255] = "";	
		if ((i <=1) || (i == compter - 1)){
			for(int l=0; l<=i; l++){
				strcat(aff, "*");	
	
			}	
			printf("%s\n", aff);
		}
		else{
			for(int l=0; l<=i; l++){
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
*/


//WHILE DO WHILE

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
