#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
int main(int argc, string argv[]){
    if(argc != 2){
        // if argument count is 1 (just the ./ compiler) then return error code
        printf("Usage: /home/cs50/pset2/vigenere <key>\n");
        return 1;
    }
    // arg count is valid
    // continue
    //
     
    // check is keyword is correct
    //
    string key = argv[1];
     for (int i = 0, n = strlen(key); i < n; i++){ // loop through every string's character for encryption
        if(isalpha(key[i])){ // check for alphabetical boolean
        } else {
            printf("./vigenere; alpha key only.\n");
            return 1; // false
        }
    }
    // keyword is correct, continue encipherment
    //
     
    string str = GetString();
    // user has entered string to encrypt
    //
    string kw = key;
    int kwL = strlen(kw);
    int kwC = 0; // keyword count - e.g; bacon. In turn, if kwC[1] = b, kwC[2] = a, kwC[i] = j;
    int n = strlen(str);
    for(int i = 0; i != n; i++){
        if(isalpha(str[i])){
            // is alpha, continue to encrypt
            if(str[i] >= 'A' && str[i] <= 'Z'){
                // if current keyword letter is upper case
                char e = str[i]; // get char to encrypt
                int  f = e; // get ascii
                int kwChar = kw[kwC];
                int toMove;
                if(isupper(kwChar)){
                    toMove = (kwChar - 65);
                } else {
                    toMove = (kwChar - 97);
                }
                //printf("\n");
                //printf("char e: %c, int e(f): %i, kwChar: %i, move: %i\n", e, f, kwChar, toMove);
                if((f + toMove) > 'Z'){ 
                    char enc = ((f + toMove) - 26);
                    printf("%c", enc);
                } else {
                    char enc = (f + toMove);
                    printf("%c", enc);
                }
            } else if(str[i] >= 'a' && str[i] <= 'z'){
                // if current keyword letter is lower case
                char e = str[i]; // get char to encrypt
                int  f = e; // get ascii
                int kwChar = kw[kwC];
                int toMove;
                if(isupper(kwChar)){
                    toMove = (kwChar - 65);
                } else {
                    toMove = (kwChar - 97);
                }
                //printf("\n");
                //printf("char e: %c, int e(f): %i, kwChar: %i, move: %i\n", e, f, kwChar, toMove);
                //                ^^            ^^          ^^        ^^                           >>-- identified place holder
                //                -- char c >>  -- int i >> -- int i  -- int i  ^ replace
  
                if((f + toMove) > 'z'){
                    char enc = ((f + toMove) - 26);
                    printf("%c", enc);
                } else {
                    char enc = (f + toMove);
                    printf("%c", enc);
                }
            }
             
            if(kwC == kwL - 1){
                kwC = 0;
            } else {
                kwC++;
            }
        } else {
            // is not alpha, continue to print
            printf("%c", str[i]);
        }
    }
    printf("\n"); // end
}
