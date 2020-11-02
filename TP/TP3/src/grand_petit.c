#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
    srand(time(NULL));
    unsigned int tab[100];

    for(unsigned char i=0;i<100;i++){ // On remplit le tableau
        tab[i] = rand()%65535;
    }

    unsigned int min = tab[0], max = tab[0];

    for(unsigned char i=0;i<100;i++){
        if(tab[i]>=max){
            max = tab[i];
        }
        if(tab[i]<=min){
            min = tab[i];
        }
    }

    printf("Max = %u et Min = %u\n", max, min);
}