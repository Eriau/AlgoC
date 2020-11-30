#include <stdio.h>

int factorielle (int num);

int main(){
    int num, res;
    printf("Entrez un nombre : \n");
    scanf("%d", &num);

    res = factorielle(num);
    printf("!%d = %d", num, res);
    return 0;
}

int factorielle (int num) {
  if (num == 0) {
    return 1;
  }
  else {
    return (num * factorielle (num-1));
  }
}