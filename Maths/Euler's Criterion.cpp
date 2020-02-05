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

long long power(long long A , long long P , long long mod){
    long long res(1); 
    A = (A%mod);
    while(P){
        if(P&1){
            res = (res*A)%mod;
        }
        P>>=1;
        A = (A*A)%mod;
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
    long long t; cin>>t;
    while(t--){
        long long A , M; cin>>A>>M;
        if(A==0){
            cout<<"YES"<<endl;
        }else if(power(A , (M-1)/2,M)==1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
