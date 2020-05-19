#include <math.h>
#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    int tempPtrOne = *a;
    int tempPtrTwo = *b;
    *b = abs(tempPtrOne - tempPtrTwo);
    *a = tempPtrOne + tempPtrTwo;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
