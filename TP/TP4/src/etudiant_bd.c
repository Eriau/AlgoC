#include <stdio.h>
#include <string.h>
#include "fichier.h"

#include <stdio.h>
#include <string.h>

typedef struct Etudiant{
	char nom[20], prenom[20], adresse[20], notesC[20], notesSysExp[20];
}Etudiant_t;

Etudiant_t etudiant(Etudiant_t etu, bool add);

int main (){

    Etudiant_t etuUn, etuDeux;
    bool add = true;

    etuUn = etudiant(etuUn, add);
    etuDeux = etudiant(etuDeux, add);

    lire_fichier("etudiant.txt");
    return 0;
}

Etudiant_t etudiant(Etudiant_t etu, bool add){
    char chaineNotesInterm[30];
    //Nom
    printf("Nom ? \n");
    lire(etu.nom, 20);
    fflush(stdin);
    ecrire_dans_fichier("etudiant.txt", strcat(etu.nom, "  "), add);
    //Prenom
    printf("Prenom ? \n");
    lire(etu.prenom, 20);
    fflush(stdin);
    ecrire_dans_fichier("etudiant.txt", strcat(etu.prenom, "  "), add);
    //Adresse
    printf("Adresse ? \n");
    lire(etu.adresse, 20);
    fflush(stdin);
    ecrire_dans_fichier("etudiant.txt", strcat(etu.adresse, "  "), add);
    //Notes C
    printf("Notes en C ? \n");
    lire(etu.notesC, 20);
    fflush(stdin);
    snprintf(chaineNotesInterm, sizeof(chaineNotesInterm), "[%s]  ", etu.notesC);
    ecrire_dans_fichier("etudiant.txt", chaineNotesInterm, add);
    //Notes sys exp
    printf("Notes en sys d'exp ? \n");
    lire(etu.notesSysExp, 20);
    fflush(stdin);
    snprintf(chaineNotesInterm, sizeof(chaineNotesInterm), "[%s]  ", etu.notesSysExp);
    ecrire_dans_fichier("etudiant.txt", chaineNotesInterm, add);
    // Retour à la ligne
    ecrire_dans_fichier("etudiant.txt", "\n", add); 
    return etu;
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
