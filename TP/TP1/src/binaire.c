#include <stdio.h>
#include <string.h>

int main(){
    char binaire[50] = "";
    char reversed_binaire[50] = "";
    int testBaseBeg = 65535;
    int done = 0;
    int count = 0;
    int t, i, j;

    int testBase = testBaseBeg;

    while(done == 0){ 
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
    reversed_binaire[t] = '\0';

    for(i = t - 1; i >= 0; i--){
        reversed_binaire[j++] = binaire[i];
    }
    reversed_binaire[i] = '\0';

    printf("%d : %s", testBaseBeg, reversed_binaire);

	return 0;
}