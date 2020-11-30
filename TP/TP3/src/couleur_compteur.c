#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define VAL_MAX 255// Pour la couleur
#define TAILLE_TAB 100

typedef struct Couleur{
	unsigned char Red, Green, Blue, Alpha;
}RGB_t;

typedef struct countCouleur{
    RGB_t couleur;
    char count;
}countCouleur_t;

void couleurCount(RGB_t *tab, char tailleTab);

int main (int argc, char* argv[]){

    srand(time(NULL));

    RGB_t tabCouleur[TAILLE_TAB];
    RGB_t colorRand; //New couleur à chaque tour de boucle

    for(unsigned char i=0;i<TAILLE_TAB;i++){ // On remplit le tableau
        colorRand.Red = rand()%VAL_MAX;
        colorRand.Green = rand()%VAL_MAX;
        colorRand.Blue = rand()%VAL_MAX;
        colorRand.Alpha = rand()%VAL_MAX;
        tabCouleur[i] = colorRand;
    }

    RGB_t jaune = {0xFF, 0xFF, 0x00, 0x00};
    RGB_t rouge = {0xFF, 0x00, 0x00, 0x00};
    RGB_t bleu = {0x00, 0x00, 0xFF, 0x00};
    RGB_t vert = {0x00, 0xFF, 0x00, 0x00};

    tabCouleur[0] = jaune;
    tabCouleur[1] = jaune;
    tabCouleur[2] = jaune;
    tabCouleur[3] = jaune;

    couleurCount(tabCouleur, TAILLE_TAB);

    return 0;
}

void couleurCount(RGB_t *tab, char tailleTab){
    RGB_t tabMultiple[tailleTab]; // On va répertorier les couleurs qui apparaissent plusieurs fois afin de les skip
    
    for(char j=0;j<tailleTab;j++){

        bool skip = false;
        countCouleur_t colorTest = {tab[j], 1}; // On va tester une couleur et choper son nombre d'occurence

        for(char w=0;w<tailleTab;w++){ // On regarde si on a déjà traité la couleur en question
            if( (colorTest.couleur.Red == tabMultiple[w].Red) && (colorTest.couleur.Green == tabMultiple[w].Green) && (colorTest.couleur.Blue == tabMultiple[w].Blue) && (colorTest.couleur.Alpha == tabMultiple[w].Alpha) ){
                skip = true;
            }
        }

        if (skip == false){
            for(char i=0;i<tailleTab;i++){ // On compare case par case
                if ( (colorTest.couleur.Red == tab[i].Red) && (colorTest.couleur.Green == tab[i].Green) && (colorTest.couleur.Blue == tab[i].Blue) && (colorTest.couleur.Alpha == tab[i].Alpha) && (i != j)){
                    colorTest.count ++;
                    tabMultiple[j] = colorTest.couleur;
                }
            }
            printf("0x%02X 0x%02X 0x%02X 0x%02X %hd\n", colorTest.couleur.Red, colorTest.couleur.Green, colorTest.couleur.Blue, colorTest.couleur.Alpha, colorTest.count);
        }else{
        }
    }
}