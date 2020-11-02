#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    int tabTest[5] = {0, 4096, 65536, 65535, 1024};

    for(unsigned char l=0;l<5;l++){
        unsigned char binaire[50] = "", reversed_binaire[50] = ""; // On initalise nos tableaux qui stockerons les bits de notre mot
        int testBase = tabTest[l], count = 0, t, i;
        bool done = false;
        unsigned char j;

        while(done != true){ // On fais une division euclidienne par deux jusqu'à que l'on arrive à 0
        
            if ((count%4 == 0) && (count != 0)){
                strcat(binaire, " ");
            }
            if (testBase < 1){
                done = 1;
            }
       
            if (testBase%2 == 0){
                strcat(binaire, "0");
            }else{
                testBase -= 1;
                strcat(binaire, "1");
            }
            testBase = testBase/2;
            count += 1;
        }
    
        j = 0;
        t = strlen(binaire);
    
        // On va inverser le contenu du tableau car la méthode ci-dessus stocke le poids fort en dernier

        for(i = t - 1; i >= 0; i--){
            reversed_binaire[j++] = binaire[i];
        }

        reversed_binaire[i] = '\0';
        printf("%d : %s\n", tabTest[l], reversed_binaire);
    }
	return 0;
}