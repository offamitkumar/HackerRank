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
//#define mod 1000000007
long long mod;
pair<long long,long long> M(pair<long long , long long>a , pair<long long,long long>b){
    pair<long long,long long>c;
    c.first = ((a.first*b.first)%mod - (a.second * b.second)%mod+mod+mod)%mod;;
    c.first = (c.first+mod+mod)%mod;
    c.second = ((a.first*b.second)%mod + (a.second * b.first)%mod)%mod;
    c.second = (c.second+mod+mod)%mod;
    return c;
}
pair<long long,long long>sol(pair<long long,long long>&com , long long k){
    pair<long long,long long>res;
    com.first = (com.first)%mod;
    com.second = (com.second)%mod;
    res.first = 1ll;
    res.second = 0ll;
    while(k){
        if(k&1){
            res = M(res,com);
        }
        com = M(com , com);
        k>>=1;
    }
    return res;
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
    int q;cin>>q;
    while(q--){
        long long k;
        pair<long long,long long>com;
        cin>>com.first>>com.second>>k>>mod;
        com = sol(com,k);
        cout<<com.first<<' '<<com.second<<endl;
    }
    return 0;
}
