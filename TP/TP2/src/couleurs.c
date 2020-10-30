#include <stdio.h>

typedef struct Couleur{
	unsigned char Red, Green, Blue, Alpha;
}RGB_t;

int main (int argc, char* argv[]){
    RGB_t jaune = {0xFF, 0xFF, 0x00, 0x00};
    RGB_t rouge = {0xFF, 0x00, 0x00, 0x00};
    RGB_t bleu = {0x00, 0x00, 0xFF, 0x00};
    RGB_t vert = {0x00, 0xFF, 0x00, 0x00};

    RGB_t tabCouleur[10] = {jaune, rouge, bleu, vert};

    for(int i=0;i<10;i++){
        printf("0x%02X%02X%02X%02X\n", tabCouleur[i].Red, tabCouleur[i].Green, tabCouleur[i].Blue, tabCouleur[i].Alpha);
    }

    return 0;
}
