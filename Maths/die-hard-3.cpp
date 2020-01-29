#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
#define mod 1000000007

// solved by using linear combination equation
int gcd(int a, int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t;cin>>t;
    while(t--){
        int a,b,c;cin>>a>>b>>c;
        if(c%gcd(a,b)==0 && c<=max(a,b)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }       
    }
    return 0;
}
