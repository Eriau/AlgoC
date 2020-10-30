#include <stdio.h>

int main(){
    unsigned char c = '+'; // On init en somme au cas ou
    short int res = 0, a = 0, b = 0;
    float resFloat = 0;
    printf("Valeur de a : \n");
    fflush(stdin); // On reset le cache
    scanf("%hd", &a);
    printf("Valeur de b : \n");
    fflush(stdin);
    scanf("%hd", &b);
    printf("Operande : ");
    fflush(stdin);
    scanf("%c", &c);

    switch(c)
    {
        case '+':
            res = a + b;
            break;
        case '*':
            res = a*b;
            break;
        case '/':
            resFloat = (float)a/(float)b;
            break;
        default:
            break;
    }

    if(c=='/'){
        printf("%hd %c %hd = %f", a, c, b, resFloat);
    }else{
        printf("%hd %c %hd = %hd", a, c, b, res);
    }
	return 0;
}

