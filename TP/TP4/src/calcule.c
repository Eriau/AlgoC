#include <stdio.h>
#include <stdlib.h>
#include "operator.h"

int main(){
    char operation;
    int a, b, res;
    float resFloat;

    if (_argc != 4)
    {
        fprintf(stderr, "Le programme a besoin d'exactement trois arguments, %s d'arguments; Exiting...\n", _argc < 4 ? "Pas assez" : "Trop");
        return -1;
    }

    if( (sscanf(_argv[1], "%d", &a) == 1) && (sscanf(_argv[2], "%c", &operation ) == 1) && (sscanf(_argv[3], "%d", &b) == 1)){
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
        }else{
            printf("%hd %c %hd = %hd", a, operation, b, res);
        }
    }else{
        printf("Erreur lors du parcours des arguments; Exiting...\n");
        return -5;
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