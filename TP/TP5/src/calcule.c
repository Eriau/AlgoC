#include <stdio.h>
#include <stdlib.h>
#include "calcule.h"

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

int calcul(int a, char operation, int b){
    int res;
    float resFloat;
    switch(operation)
    {
        case '+':
            res = somme(a,b);
            break;
        case '-':
            res = difference(a, b);
            break;
        case 'x': // Avec * à la place de x j'ai 20 arguments je ne sais pas pourquoi
            res = produit(a, b);
            break;
        case '/':
            if(b==0){
                printf("Division par zéro impossible; Exiting...\n");
                return -2;
            }
            resFloat = quotient(a, b);
            break;
        case '%':
            if(b==0){
                printf("Division par zéro impossible; Exiting...\n");
                return -3;
            }
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
            printf("Operateur invalide : '%c'; Exiting...\n", operation);
            return -4;
    }
    if(operation =='/'){
        printf("%hd %c %hd = %f", a, operation, b, resFloat);
        return(resFloat);
    }else{
        printf("%hd %c %hd = %hd", a, operation, b, res);
        return(res);
    }
}