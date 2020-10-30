#include <stdio.h>

int main (int argc, char* argv[]){
    int u_zero = 1, u_un = 1, u_n = 0, u_n_moins_un = 0, u_n_moins_deux = 0;
    int n = 0;
    printf("Rang ? : \n");
    scanf("%d",&n);
    
    u_n_moins_un = u_un;
    u_n_moins_deux = u_zero;
    printf("%d\n", u_zero);
    printf("%d\n", u_un);
    
    for(int i=0;i<(n-2);i++){
        u_n = u_n_moins_un + u_n_moins_deux;
        u_n_moins_deux = u_n_moins_un;
        u_n_moins_un = u_n; 
        printf("%d\n", u_n);
    }
    return 0;
}