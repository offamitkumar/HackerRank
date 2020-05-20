#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.
int max(int firstNumber , int secondNumber){
    return (firstNumber > secondNumber)?firstNumber:secondNumber;
}

void calculate_the_maximum(int n, int k) {
  //Write your code here.
    int resultOr=0 , resultAnd=0 , resultXor=0;
    for(int i=1;i<n;++i){
        for(int j=i+1;j<=n;++j){
            resultOr = max(resultOr , ((( i|j )<k)?( i|j ):0 ));
            resultAnd = max(resultAnd , ( (( i&j )<k)?( i&j ):0 ));
            resultXor = max(resultXor , ( (( i^j )<k)?( i^j ):0 ));
        }
    }
    printf("%d\n%d\n%d",resultAnd , resultOr , resultXor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
