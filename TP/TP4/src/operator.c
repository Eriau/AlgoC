#include <stdio.h>
#include "operator.h"

int main(){
    unsigned char c ; 
    int res = 0, a = 0, b = 0;
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
            res = somme(a,b);
            break;
        case '-':
            res = difference(a, b);
            break;
        case '*':
            res = produit(a, b);
            break;
        case '/':
            resFloat = quotient(a, b);
            break;
        case '%':
            res = modulo(a, b);
            break;
        case '&':
            res = et(a, b);
            break;
        case '|':
            res = ou(a, b);
            break;
        case '~':
            res = negation(a);
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

int somme(int num1, int num2){
    int res = num1 + num2;
    return res;
}

int difference(int num1, int num2){
    int res = num1 - num2;
    return res;
}

int produit(int num1, int num2){
    int res = num1*num2;
    return res;
}

float quotient(int num1, int num2){
    float res = (float)num1/(float)num2;
    return res;
}

int modulo(int num1, int num2){
    int res = num1%num2;
    return res;
}

int et(int num1, int num2){
    int res = num1&num2;
    return res;
}

int ou(int num1, int num2){
    int res = num1|num2;
    return res;
}

int negation(int num){
    int res = ~num;
    return res;
}