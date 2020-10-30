#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void affTabInt(int *tab, int tailleTab);
void affTabFloat(float *tab, int tailleTab);

int main (int argc, char* argv[]){
    srand(time(NULL)); // Permet d'avoir des nombres random diff entre chaque exec du programme

    int tabUn[10];
    float tabDeux[10];
    for(int i=0;i<10;i++){
        *(tabUn + i)=rand()%100;  // tabUn[i] <-> *(tabUn +i)
        *(tabDeux + i)=((float)rand()/RAND_MAX)*100;
    }

    affTabInt(tabUn, 10);
    affTabFloat(tabDeux, 10);

    printf("\n");

    for(int i=0;i<10;i++){
        if((i%2==0)&&(i!=0)){
            *(tabUn + i) *= 3;
            *(tabDeux + i) *= 3;
        }
    }

    affTabInt(tabUn, 10);
    affTabFloat(tabDeux, 10);

    return 0;
}


//Probablement possible de tester le type dans notre tab et de print en fonction..
void affTabInt(int *tab, int tailleTab){
    for(int i=0;i<tailleTab;i++){
        printf("%d ", *(tab + i));
    }
    printf("\n");
}

void affTabFloat(float *tab, int tailleTab){
    for(int i=0;i<tailleTab;i++){
        printf("%f ", *(tab + i));
    }
    printf("\n");
}