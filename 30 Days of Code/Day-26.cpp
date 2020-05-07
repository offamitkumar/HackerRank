
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */     int dd , mm , yy;
    int DD , MM , YY;
    cin>>dd>>mm>>yy>>DD>>MM>>YY;
    long long fine{};
    if(dd > DD && MM==mm && YY == yy){
        fine+=abs(dd-DD)*15;
    }
    if(MM < mm && YY == yy){
        fine+=(abs(MM-mm))*500;
    }
    if(YY < yy){
        fine+=10000;
    }
    cout<<fine<<endl;
    return 0;
}
