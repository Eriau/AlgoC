#include <stdio.h>

int main (int argc, char* argv[]){
    printf("%zu\n",sizeof (int));
    printf("%zu\n",sizeof (int *));
    printf("%zu\n",sizeof (int **));
    printf("%zu\n",sizeof (char *));
    printf("%zu\n",sizeof (char **));
    printf("%zu\n",sizeof (char ***));
    printf("%zu\n",sizeof (float *));
    printf("%zu\n",sizeof (float **));
    printf("%zu\n",sizeof (float ***));
    return 0;
}