#include <bits/stdc++.h>
using namespace std;

int64_t mod;
pair<int64_t,int64_t> M(pair<int64_t , int64_t>a , pair<int64_t,int64_t>b){
    pair<int64_t,int64_t>c;
    c.first = ((a.first*b.first)%mod - (a.second * b.second)%mod+mod)%mod;;
    c.second = ((a.first*b.second)%mod + (a.second * b.first)%mod)%mod;
    return c;
}
pair<int64_t,int64_t>sol(pair<int64_t,int64_t>&com , int64_t k){
    pair<int64_t,int64_t>res;
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
        int64_t k;
        pair<int64_t,int64_t>com;
        cin>>com.first>>com.second>>k>>mod;
        com = sol(com,k);
        cout<<com.first<<' '<<com.second<<endl;
    }
    return 0;
}
