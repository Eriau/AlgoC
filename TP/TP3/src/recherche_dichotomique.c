#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAILLE_TAB 50
#define VAL_MAX 65535

void tri(int *tab, unsigned char tailleTab);
void rechercheDico(unsigned int elem, int *tabSorted, unsigned char tailleTab, bool *done);
void afficheTab(int *tab, unsigned char tailleTab);

int main (int argc, char* argv[]){
    srand(time(NULL));
    unsigned int tab[TAILLE_TAB];

    for(char i=0;i<TAILLE_TAB;i++){ // On remplit le tableau
        tab[i] = rand()%VAL_MAX;
    }

    tab[25] = 954; // On affecte une valeur connue et on change l'entier test pour s'assurer que tout fonctionne
    unsigned int entierTest = 54;
    bool done = false;

    tri(tab, TAILLE_TAB);
    afficheTab(tab, TAILLE_TAB);
    printf("\n");

    while(done == false){
        rechercheDico(entierTest, tab, TAILLE_TAB, &done);
    }

    return 0;
}

void tri(int *tab, unsigned char tailleTab){
    unsigned int intermUn = 0, intermDeux = 0; // Permet de garder la valeur pendant l'échange pour le tri du tableau
    char numbIntToSort = tailleTab, j = 0, h = TAILLE_TAB - 1;

    while(numbIntToSort != 0){
        char indMin = j, indMax = j;
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
}

void rechercheDico(unsigned int elem, int *tab, unsigned char tailleTab, bool *done){
    unsigned char m = tailleTab/2; // On coupe le tableau en deux
    if(tab[m] == elem){
        printf("Entier present \n");
        *done = true; // Si l'elem est présent, on passe le flag done en true pour arrêter la recherche
    }else if (m == 0){
        *done = true; // Si on a fait la totalité du tableau on passe le flag done en true pour arrêter la recherche
        printf("Entier non present \n");
    }else if (tab[m] > elem){
        rechercheDico(elem, tab, m, done); // Si l'élement est plus grand que tab[m], comme le tableau est trié, on va rechercher dans la moitié basse du tableau et ainsi desuite
    }else{
        rechercheDico(elem, &tab[m+1], m, done); // Si l'élement est plus petit, partie haute ...
    }
}

void afficheTab(int *tab, unsigned char tailleTab){
    for(int i=0;i<tailleTab;i++){
        printf("%d ", tab[i]);
    }
}