#include <stdio.h>

int main (int argc, char* argv[]){
    char chaine_un[20] = "Bonjour";
    char chaine_deux[10] = "Au revoir";
    char chaine_copie[10] = {0};
    int test = 1, i = 0, j = 0, k = 0;

    // Taille chaine car
    while(test == 1){
        i++;
        if(chaine_un[i] == '\0'){
            test = 0;
        }
    }

    //Copie
    while(chaine_un[j] != '\0'){
        chaine_copie[j] = chaine_un[j];
        j++;
    }
    
    chaine_copie[j+1] = '\0';
    printf("Taille chaine un : %d\n", i);
    printf("%s\n", chaine_copie);

    //Concatenation
    while(chaine_deux[k] != '\0'){
        chaine_un[i] = chaine_deux[k];
        i++;
        k++;
    }
    chaine_un[i+k] = '\0';
    printf("%s\n", chaine_un);
    
    return 0;
}