#include <stdio.h>
#include <math.h>

int main (int argc, char* argv[]){
    unsigned int d;
    printf("Rentrez un nombre : `\n");
    scanf("%d",&d);
    if (((d & 0b1000) != 0 ) && ((d & 0b1000000000000000000) != 0)){
        printf("1\n");
    }else{
        printf("0\n");
    }
    return 0;
}