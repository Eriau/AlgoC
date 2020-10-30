#include <stdio.h>

int main (int argc, char* argv[]){
    short int a, b, res;
    printf("Rentrez un nombre : \n");
    fflush(stdin);
    scanf("%d",&a);
    printf("Un autre: \n");
    fflush(stdin);
    scanf("%d",&b);
    
    res = a;

    for(int i=1;i<b;i++){
        res = res * a;
    }

    printf("%d^%d = %d \n", a, b, res);
    
    return 0;
}
