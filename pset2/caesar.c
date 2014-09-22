#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
int main(int argc, string argv[]){
    if(argc != 2){
        // if argument count is 1 (just the ./ compiler) then return error code //basically rendered useless now
        printf("Usage: /home/cs50/pset2/caesar <key>\n");
        return 1;
    }
    // arg count is valid
    // continue
    //
    string str = GetString();
    // user has entered string to encrypt
    //
    int k = atoi(argv[1]);
    int key = (k % 26);
    // final key has been returned~
    //
     
    for (int i = 0, n = strlen(str); i < n; i++){
        if(isalpha(str[i])){
        // is valid character, begin encryption
         
            if(isupper(str[i])){
                // char is upper - encrypt for upper case (65 - 90)
                int ascii = str[i]; // get ascii value - check if we need to wrap round
                 
                if((ascii + key) > 90){ // needs to be wrapped, -26
                    // we need to wrap
                    int toPrint = ((ascii + key) - 26); // wrapped value
                    printf("%c", toPrint);
                } else if ((ascii + key) < 65){
                    // this is incase a negative key has been entered
                    int toPrint = ((ascii + key) + 25); // wrapped value
                    printf("%c", toPrint);
                } else {
                // doesn't need wrapping, continue printing
                printf("%c", str[i] + key);
                }
            } else {
                // chas is lower - encrypt for lower case (97 - 122)
                int ascii = str[i]; // get ascii value - check if we need to wrap round
                 
                if((ascii + key) > 122){ // needs to be wrapped, -26
                    //we need to wrap
                    int toPrint = ((ascii + key) - 26); // wrapped value
                    printf("%c", toPrint);
                } else if ((ascii + key) < 97){
                    // this is incase a negative key has been entered
                    int toPrint = ((ascii + key) + 26);
                    printf("%c", toPrint);
                } else {
                // doesn't need wrapping, continue printing
                printf("%c", str[i] + key);
                }
            }
        } else {
        // invalid character - print anyway
        printf("%c", str[i]);
        }
    }
    printf("\n"); // end  
}
