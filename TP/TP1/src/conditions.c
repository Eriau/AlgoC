#include <stdio.h>

int main(){
    for (int i=0; i<1001;i++){
        if ((i%2 == 0) && (i%15 == 0)){ 
            printf("%hd\n", i);
        }
        else if ((i%103 == 0) || (i%107 == 0)){ 
            printf("%hd\n", i);
        }
        else if (((i%7 == 0) || (i%5 == 0)) && (i%3 != 0)){  // Potentiellement uniquement vérifier si c'est divisible par 3 puis break, et si c'est non divisible regarder le reste ?
            printf("%hd\n", i);
        }
    }    
	return 0;
}

