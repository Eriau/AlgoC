#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 300 //Nmbre de car max par ligne dans notre fichier test.txt (Possibilité de l'agrandir)

void lookFor(char *nomFichier, char* msgToFind);

int main(){    
    char nomFichier[50], msgToFind[50];

    if (_argc != 3)
    {
        fprintf(stderr, "Le programme a besoin d'exactement deux arguments, %s d'arguments; Exiting...\n", _argc < 3 ? "Pas assez" : "Trop");
        return -1;
    }

    if( (sscanf(_argv[1], "%s", &msgToFind) == 1) && (sscanf(_argv[2], "%s", &nomFichier ) == 1) ){
        lookFor(nomFichier, msgToFind);
    }else{
        printf("Erreur lors du parcours des arguments; Exiting...\n");
        return -5;
    }
}

void lookFor(char *nomFichier, char* msgToFind){
    FILE* fichier = NULL; // La fonction fopen renvoie un FILE* donc on crée cette variable pour récupérer le pointeut que nous renverra la fonction fopen
    char * buffer = (char *) malloc( MAX_LENGTH ); // On alloue la mémoire nécéssaire à notre chaine de car 
    bool noMatch = true;
    fichier = fopen(nomFichier, "r"); // On ouvre notre fichier en lecture seulement
    if(fichier!=NULL){
        char line = 1;
        while(!feof(fichier)){ // Tant que l'on est pas en fin de fichier on affiche le contenu
            fgets(buffer, MAX_LENGTH, fichier); 
            if(strstr(buffer, "\n") == NULL){ // Si on est a la dernière ligne du fichier on rajoute un saut à la ligne pour éviter des pb avec strstr
                strcat(buffer, "\n");
            }
            char lenLine = strlen(buffer);
            char lenMsg = strlen(msgToFind);
            char count = 0;
            for(char i=0; i<lenLine-lenMsg;i++){
                if(strstr(buffer + i, msgToFind) == buffer + i){ // strstr renvoie un pointeur vers l'occurence
                    count++;
                    i = i + lenMsg - 1; // Si on trouve une occurence on fait un saut de la taille du mot
                }
            }
            if(count != 0){
                printf("Ligne %hd : %hd fois\n", line, count);
                noMatch = false;
            }
            line++;
        }
        if(noMatch){
            printf("Aucune occurence \n");
        }
        fclose(fichier); // On ferme notre fichier
    }else{
        printf("Impossible d'ouvrir le fichier %s\n", nomFichier); // En cas de problème on l'indique à l'utilisateur
    }
    free(buffer); // Libération de la mémoire
}