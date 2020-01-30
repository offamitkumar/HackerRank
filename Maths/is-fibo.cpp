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
array<long long,1000000>fib;
set<long long>s;
void pre(void){
    fib[0] = 0ll;
    fib[1] = 1ll;
    s.insert(0);
    s.insert(1);
    long long sum = 0ll;
    for(int i=2;sum<10e10;++i){
        sum = fib[i-1]+fib[i-2];
        if(sum>10e10){
            break;
        }
        fib[i] = sum;
        s.insert(fib.at(i));
    }
    return;
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
    pre();
    int t;cin>>t;
    while(t--){
        long long n; cin>>n;
        if(s.count(n)){
            cout<<"IsFibo"<<endl;
        }else{
            cout<<"IsNotFibo"<<endl;
        }
    }
    return 0;
}
