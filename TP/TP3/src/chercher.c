#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAILLE_TAB 50

int main (int argc, char* argv[]){
    srand(time(NULL));
    unsigned int tab[TAILLE_TAB];

    for(unsigned char i=0;i<TAILLE_TAB;i++){ // On remplit le tableau
        tab[i] = rand()%65535;
    }

    unsigned int entierTest = 25189;
    unsigned char done = 0, i = 0;

    while((done != 1)&&(i<TAILLE_TAB)){
        if (tab[i] == entierTest){
            printf("Entier present \n");
            done = 1;
        }else{}
        i++;
    }

    if(done==0){
        printf("Entier non present\n");
    }
}