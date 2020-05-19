#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    for(int n =a; n<=b; ++n){
        if(!(n^1))
            puts("one");
        else if(!(n^2))
            puts("two");
        else if(!(n^3))
            puts("three");
        else if(!(n^4))
            puts("four");
        else if(!(n^5))
            puts("five");
        else if(!(n^6))
            puts("six");
        else if(!(n^7))
            puts("seven");
        else if(!(n^8))
            puts("eight");
        else if(!(n^9))
            puts("nine");
        else{
            if(n&1)
                puts("odd");
            else
                puts("even");
        }
    }
    return 0;
}

