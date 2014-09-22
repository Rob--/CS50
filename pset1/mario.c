#include <stdio.h>
#include <cs50.h>
 
int main(void) {
    int n;
    do
    {
    printf("Height? ");
    n = GetInt();
    }
    while (n > 23 || n < 0);
    // start writing
     
    int spaces;
    int hashes = 2;
    int times;
    for(times = 1; times < (n + 1); times++) {
        // start looping
        //
     
        // make spaces
        spaces = n - times;
        int a;
        for(a = 0; a != spaces; a++){
            printf(" ");
        }
        // end spaces
         
        // make hashes
        int b;
        for(b = 0; b != hashes; b++){
            printf("#");
        }
        // end hashes
     
        //
        // end looping
        printf("\n");
        hashes = hashes + 1;
    }
}
