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
    set<int>sqr;
    for(int i=2;i*i<=2002000;i+=2){
        sqr.insert(i*i);
    }
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        set<int>factor;
        int counter{};
        factor.insert(1);
        for(int i=2;i*i<n+1;++i){
            if(n%i==0){
                factor.insert(i);
                if(sqr.find(i)!=sqr.end()){
                    counter++;
                }
                factor.insert(n/i);
                if(n/i!=i){
                    if(sqr.find(n/i)!=sqr.end()){
                        counter++;
                    }
                }
            }
        }
        if(counter==0){
             cout<<0<<endl;
        }else{
            int gcd = __gcd(int(counter),int(factor.size()));
            cout<<counter/gcd <<'/'<<factor.size()/gcd<<endl;
        }
    }
    return 0;
}
