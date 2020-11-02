#include <stdio.h>
#include <stdbool.h>

void cherche_phrase(char *tab[], unsigned char tailleTab, char *msg);

int main(){
    char *tabPhrase[10] = {"Bonjour", "Super", "Non", "Oui", "Wow", "Le pain", "Le pate", "Ok super", "Ba pourquoi pas", "Fin"};
    cherche_phrase(tabPhrase, 10, "Bonour");
    return 0;
}

void cherche_phrase(char *tab[], unsigned char tailleTab, char *msg){
    bool not_here = false;
    char **ptrSurString = &tab[0]; // On fait un pointeur qui pointe sur le pointeur qui pointe sur la phrase
    for(unsigned char i=0;i<tailleTab;i++){
        if(*ptrSurString == msg){
            printf("Message present\n");
            not_here = false;
            break;
        }else{
            not_here = true;
        }
        ptrSurString++; // On passe à la case suivante du tableau
    }
    if(not_here==true){
        printf("Non present \n");
    }
}