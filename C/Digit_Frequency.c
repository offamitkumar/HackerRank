#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char str[1000];
    scanf("%d",str);
    int freqCounter[10] = {0};
    for(int i=0;i<(int)strlen(str);++i){
        if(str[i]<='0' && str[i]>='9'){
            freqCounter[str[i]-'a']++;
        }
    }
    for(int i=0;i<10;++i){
        printf("%d ",freqCounter[i]);
    }
    return 0;
}
