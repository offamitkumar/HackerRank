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



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    long long n; cin>>n;
    vector<long long>v(n);
    for(auto&itr:v){
        cin>>itr;
    }
    if((int)v.size()==1){
        cout<<v.at(0)+1<<endl;
        return 0;
    }
    vector<long long>l_gcd(n+2,0ll);
    vector<long long>r_gcd(n+2,0ll);
    l_gcd.at(0) = 0;
    r_gcd.at(n-1) = 0;
    for(int i=1;i<=n;++i){
        l_gcd.at(i) = __gcd(l_gcd.at(i-1),v.at(i-1));
    }
    for(int i=n-2;i>=0;--i){
        r_gcd.at(i) = __gcd(r_gcd.at(i+1),v.at(i+1));
    }
    long long ans=0;
    for(int i=0;i<=n;++i){
        long long gcd = __gcd(l_gcd.at(i),r_gcd.at(i));
        if(v[i]%gcd!=0)ans=gcd;
    }
    cout<<ans<<endl;
    return 0;
}
