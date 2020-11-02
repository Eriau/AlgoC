#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_TAB 20
#define VAL_MAX 65535

void tri(int *tab, unsigned char tailleTab);

int main (int argc, char* argv[]){
    srand(time(NULL));
    unsigned int tab[TAILLE_TAB];

    
    for(unsigned char i=0;i<TAILLE_TAB;i++){ // On remplit le tableau
        tab[i] = rand()%VAL_MAX;
    }
    

    for(unsigned char i=0;i<TAILLE_TAB;i++){ // Mieux sous forme de fonction mais bon
        printf("%u ", tab[i]);
    }

    printf("\n");
    printf("\n");

    tri(tab, TAILLE_TAB);    
}


void tri(int *tab, unsigned char tailleTab){
    unsigned int intermUn = 0, intermDeux = 0; // Permet de garder la valeur pendant l'échange pour le tri du tableau
    unsigned char numbIntToSort = tailleTab, j = 0, h = TAILLE_TAB - 1;

    while(numbIntToSort != 0){
        unsigned char indMin = j, indMax = j;
        unsigned int min = tab[j];  // On assigne une valeur arbitraire pour le min et le max
        unsigned int max = tab[j];

        for(char i=j;i<h+1;i++){ // On cherche la valeur min et la valeur max parmi les entiers non triés du tableau
            if(tab[i]>max){
                max = tab[i];
                indMax = i;
            }
            if(tab[i]<min){
                min = tab[i];
                indMin = i;
             }
        }

        if(indMin != j){ // Si le minimum est déjà au bon endroit on ne fait rien
            intermUn = tab[j];
            tab[j] = min;
            tab[indMin] = intermUn;
            if(intermUn==max){ // Si la valeur que l'on va switch est la valeur max, on s'assure de changer son indice
                indMax = indMin;
            }
        }

        if(indMax != h){ // Si le max est déjà au bon endroit on ne fait rien
            intermDeux = tab[h];
            tab[h] = max;
            tab[indMax] = intermDeux;
        }
 
        numbIntToSort -= 2;
        j++;
        h--;
    }

    for(unsigned char i=0;i<tailleTab;i++){ // On affiche le tableau
        printf("%u ", tab[i]);
    }
}

