#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int firstIntNumber , secondIntNumber;
    double firstFloatNumber , secondFloatNumber;
    scanf("%d%d%lf%lf",&firstIntNumber, &secondIntNumber,&firstFloatNumber, &secondFloatNumber);
    printf("%d %d \n%.1lf %.1lf\n",firstIntNumber+secondIntNumber , firstIntNumber - secondIntNumber , firstFloatNumber+secondFloatNumber , firstFloatNumber-secondFloatNumber);
    return 0;
}
