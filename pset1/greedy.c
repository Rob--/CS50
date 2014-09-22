#include <stdio.h>
#include <cs50.h>
#include "math.h"
 
int main(void){
    float change;
    do {
        printf("Change due:\n");
        change = GetFloat();    
    } while(change < 0);
    change = change * 100; // change from dollars
    int newChange = (int) round(change); // float to int, round int 
     
    // finished getting change due
    int coins = 0;
     
    // do for 0.25
    if(newChange >= 25){
        do {
            newChange = newChange - 25;
            coins = coins + 1;
        } while(newChange >= 25);
    }
    //
     
    // do for 0.10
    if(newChange >= 10){
        do {
            newChange = newChange - 10;
            coins = coins + 1;
        } while(newChange >= 10);
    }
    //
     
    // do for 0.5
    if(newChange >= 5){
        do {
            newChange = newChange - 5;
            coins = coins + 1;
        } while(newChange >= 5);
    }
    //
     
    // do for 0.1
    if(newChange >= 1){
        do {
            newChange = newChange - 1;
            coins = coins + 1;
        } while(newChange >= 1);
    }
    //
    printf("%i\n", coins); 
}
