#include "repertoire.h"
#include "dirent.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include <stdio.h>

int main(){
    lire_dossier_recursif("/home/eriau/Documents/AlgoC/TP/TP1");
    return 0;
}

void lire_dossier(char *rep){
    struct dirent *de;

    DIR *dr = opendir(rep);

    if (dr == NULL)
    {
        printf("Impossible d'ouvrir le répertoire" );
    }

    while ((de = readdir(dr)) != NULL)
        printf("%s\n", de->d_name);

    closedir(dr);
}

void lire_dossier_recursif(char *rep){
    struct dirent *de;

    DIR *dr = opendir(rep);

    if (dr == NULL)
    {
        printf("Impossible d'ouvrir le répertoire" );
    }
    printf("\n");

    while ((de = readdir(dr)) != NULL){
        if(de->d_type == DT_DIR){
            if(strcmp(de->d_name,"..") != 0 && strcmp(de->d_name,".") != 0 && strcmp(de->d_name,".git") != 0){  // On compare le nom du dir avec ".." et "." car on ne veut pas afficher ces élément, on pourrait faire ce test avec un .git par exemple si on veut pas voir ce genre de fichier
                char *temp = malloc(strlen(rep) + strlen("/")+256); /* On alloue la place nécessaire au nouveau string */
                strcat(temp, rep);
                strcat(temp, "/");
                strcat(temp, de->d_name);
                printf("\n");

                printf("%s: \n", temp);
                lire_dossier_recursif(temp);
            }else{
            }
        }else{
            printf("%s  ", de->d_name);
        }
    }
    closedir(dr);
}