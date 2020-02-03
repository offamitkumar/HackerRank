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
long long mod;
long long mod_power( long long a, long long b){
    long long res=1;
    while(b){
        if(b&1){
             res = (res * a)%mod;
        }
        a  = (a*a)%mod;
        b>>=1;
    }
    return res;
}
long long mod_inverse( long long a){
    return mod_power(a , mod-2);
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
    long long t;cin>>t;
    while(t--){
        long long a , b; cin>>a>>b>>mod;
        long long ans{};
        if(b>=0){
            ans = mod_power(a , b);
        }else{
            ans = mod_power(mod_inverse(a),-b);
        }
        ans = (ans+mod+mod)%mod;
        cout<<ans<<endl;
    }

    return 0;
}
