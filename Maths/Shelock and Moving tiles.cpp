#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long ll;
 
int main() {  
    ll l,s1,s2,q,qi;
    cin>>l>>s1>>s2>>q;
    if(s1 > s2) swap(s1,s2);
    while(q--){
        cin>>qi;
        cout<<setprecision(10)<<fixed;
        cout<<(l*sqrt(2)-sqrt(2*qi))/(s2-s1)<<endl;
    }
    return 0;
}
