#include <stdio.h>

typedef struct Couleur{
	unsigned char Red, Green, Blue, Alpha;
}RGB_t;

int main (int argc, char* argv[]){
    RGB_t jaune = {0xFF, 0xFF, 0x00, 0x00};
    RGB_t rouge = {0xFF, 0x00, 0x00, 0x00};
    RGB_t bleu = {0x00, 0x00, 0xFF, 0x00};
    RGB_t vert = {0x00, 0xFF, 0x00, 0x00};

    RGB_t tabCouleur[100] = {jaune, rouge, bleu, vert};

    for(unsigned char i=0;i<100;i++){
        printf("%x %x %x %x %hd\n", tabCouleur[i].Red, tabCouleur[i].Green, tabCouleur[i].Blue, tabCouleur[i].Alpha, i);
    }

    return 0;
}
