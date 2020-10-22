#include <stdio.h>

int main(){
    short a,b,res;
    char c = '+'; // + & / a voir comment faire la rentrée
    printf("Valeur de a : \n");
    scanf("%hd", &a);
    printf("Valeur de b : \n");
    scanf("%hd", &b);
    switch(c)
    {
        case '+':
            res = a + b;
            break;
        case '*':
            res = a*b;
            break;
        case '/':
            res = a/b;
            break;
        default:
            break;
    }
    printf("%hd %c %hd = %hd", a, c, b, res);
	return 0;
}

