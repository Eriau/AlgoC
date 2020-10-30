#include <stdio.h>
#include <math.h>

int main (int argc, char* argv[]){
    unsigned int d;
    printf("Rentrez un nombre : `\n");
    fflush(stdin);
    scanf("%d",&d);
    if ((d & 0b10000000000000001000) != 0){ // On vérifie si l'opération & bit à bit sur le 4ème et 20ème bit est bien différente de 0, si c'est le cas alors les deux bits sont à 1
        printf("1\n");
    }else{
        printf("0\n");
    }
    return 0;
}