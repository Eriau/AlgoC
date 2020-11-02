#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"

int main(){    
    char msg[50], nom_de_fichier[50] = "test.txt";
    bool add = true;
    printf("Veuillez rentrer le message que vous voulez mettre dans le fichier : \n");
    lire(msg, 50);
    lire_fichier(nom_de_fichier);
    ecrire_dans_fichier(nom_de_fichier, msg, add);
    lire_fichier(nom_de_fichier);
    return 0;
}

void lire_fichier(char *nom_de_fichier){
    FILE* fichier = NULL; // La fonction fopen renvoie un FILE* donc on crée cette variable pour récupérer le pointeut que nous renverra la fonction fopen
    int carActuel = 0;
    fichier = fopen(nom_de_fichier, "r"); // On ouvre notre fichier en lecture seulement
    if(fichier!=NULL){
        while(carActuel != EOF){ // Tant que l'on est pas en fin de fichier on affiche le contenu
            carActuel = fgetc(fichier);
            printf("%c", carActuel);
        }
        fclose(fichier); // On ferme notre fichier
    }else{
        printf("Impossible d'ouvrir le fichier %s\n", nom_de_fichier); // En cas de problème on l'indique à l'utilisateur
    }
    printf("\n\n");
}

// On pourrait utiliser fprintf pour écrire un message formaté (voir lien dans READ ME pour plus d'info)
void ecrire_dans_fichier(char *nom_de_fichier, char *message, bool add){
    FILE* fichier = NULL; // La fonction fopen renvoie un FILE* donc on crée cette variable pour récupérer le pointeut que nous renverra la fonction fopen
    if(add == false){
        fichier = fopen(nom_de_fichier, "w"); // On ouvre notre fichier en ecriture seulement
    }else if(add == true){
        fichier = fopen(nom_de_fichier, "a"); // On ouvre notre fichier en ajout
    }
    if(fichier!=NULL){
        fputs(message, fichier);
        fclose(fichier); // On ferme notre fichier
    }else{
        printf("Impossible d'ouvrir le fichier %s", nom_de_fichier); // En cas de problème on l'indique à l'utilisateur
    }    
}

void vider_buffer(){ // S'assure de clean le buffer si l'on rentre trop de caractères puisque fgets ne clean pas le buffer donc dés que l'on a lu nos caractères on va commencer à voir ceux en trop
    int c = 0;
    while(c != '\n' && c != EOF){
        c = getchar();
    }
}

// Fonction pour taper une chaine de caractère
int lire(char *chaine, int longueur){ 
    char *positionBase = NULL; 
    if(fgets(chaine, longueur, stdin) != NULL){ // S'il n y a pas d'erreur de saisie :
        positionBase = strchr(chaine, '\n'); // On recherche le saut à la ligne car fgets ne le supprime pas
        if(positionBase != NULL){
            *positionBase = '\0'; // On remplace le saut à la ligne par ce qui représente la fin d'une chaîne de caractère
        }else{
            vider_buffer();
        }
        return 1; // On renvoie 1 s'il n y a pas d'erreurs
    }else{
        vider_buffer();
        return 0; // On renvoie 0 en cas d'erreur
    }
}
