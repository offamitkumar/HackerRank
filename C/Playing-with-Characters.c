#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */     char a , arr[20] , ar[1000];
    scanf("%c",&a);
    scanf("%s",arr);
    scanf("\n");
    scanf("%[^\n]%*c" , ar);
    printf("%c\n",a);
    printf("%s\n",arr);
    for(int i=0;i<strlen(ar);++i){
        printf("%c",ar[i]);
    }
    return 0;
}
