#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
     long long r,c,num; cin>>r>>c; 
     if(r%2 == 0) {
          num = 10*((r/2)-1)+1;
          num = num + 2*(c-1);
     } else {
          num = 10*(r/2);
          num = num + 2*(c-1);
     }
     cout<<num<<endl;
     return 0;
}

