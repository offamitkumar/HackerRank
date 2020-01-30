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
array<long long,2000001>fact;
void pre(void){
    fact[0] = 1;
    for(int i=1;i<(int)fact.size();++i){
        fact[i] = (fact[i-1]*i)%mod;
    }
}
long long power(long long x, long long p){
    long long res = 1ll;
    while(p){
        if(p&1){
            res = (res * x)%mod;
        }
        x = (x*x)%mod;
        p>>=1;
    }
    return res;
}
long long inv(long long x){
    x%=mod;
    return power(x , mod-2ll);
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
        int n,m;cin>>m>>n;
        long long ans = (fact[n+m-2]*inv(fact[n-1])%mod+mod)%mod;
        ans = (ans * inv(fact[m-1])%mod+mod)%mod;
        ans = (ans + mod +mod)%mod;
        cout<<ans<<endl;
    }
    return 0;
}
