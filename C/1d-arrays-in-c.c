#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    // i could solve this with one for loop and without array
    // but let's just don't spoil the motive of HackerRank
    int n; 
    scanf("%d",&n);
    int *array = (int*)malloc(n * sizeof(int));
    for(int i=0;i<n; ++i){
        scanf("%d",&arr[i]);
    }
    int sum=0;
    for(int i=0;i<n;++i){
        sum += arr[i];
    }
    printf("%d",sum);
    return 0;
}
