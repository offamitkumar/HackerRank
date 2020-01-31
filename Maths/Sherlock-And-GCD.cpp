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
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        int gcd;
        bool ok = true;
        while(n--){
            int x; cin>>x;
            if(ok){
                gcd = x;
                ok=!ok;
                continue;
            }
            gcd = __gcd(gcd , x);
        }
        if(gcd==1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
