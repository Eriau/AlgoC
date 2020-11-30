#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

int main(){    
    RGB_t jaune = {0xFF, 0xFF, 0x00, 0x00};
    RGB_t rouge = {0xFF, 0x00, 0x00, 0x00};
    RGB_t bleu = {0x00, 0x00, 0xFF, 0x00};
    RGB_t vert = {0x00, 0xFF, 0x00, 0x00};

    ListCouleurs *maListe = init();

    insertion(&jaune, maListe);
    insertion(&rouge, maListe);
    insertion(&bleu, maListe);
    insertion(&vert, maListe);

    parcours(maListe);

    return 0;
}

ListCouleurs *init(){ // On crée la structure de contrôle et le premier élement de la liste

    ListCouleurs *liste = malloc(sizeof(*liste));
    Couleur *couleur = malloc(sizeof(*couleur));

    if (liste == NULL || couleur == NULL){
        exit(EXIT_FAILURE);
    }

    couleur->rgb.Red = 0;
    couleur->rgb.Green = 0;
    couleur->rgb.Blue = 0;
    couleur->rgb.Alpha = 0;
    couleur->suivant = NULL;
    liste->premier = couleur;

    return liste;
}

void insertion (RGB_t *newCouleur, ListCouleurs *liste){
    Couleur *new = malloc(sizeof(*new)); // Nouvel élement
    if (liste == NULL || new == NULL){
        exit(EXIT_FAILURE);
    }
    new->rgb =  *newCouleur;

    // Insertion de l'élém au début de la liste
    new->suivant = liste->premier;
    liste->premier=new;
}

void parcours (ListCouleurs *liste){
    if(liste==NULL){
        exit(EXIT_FAILURE);
    }

    Couleur *actuel = liste->premier;

    while(actuel != NULL){
        printf("0x%02X%02X%02X%02X\n", actuel->rgb.Red, actuel->rgb.Green, actuel->rgb.Blue, actuel->rgb.Alpha);
        actuel = actuel->suivant;
    }
}