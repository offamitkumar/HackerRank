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
#define mod 1000000000

array<array<int,2000>,2000>nCr;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    nCr[1][0] = nCr[1][1] = 1;
    for(int i=2;i<(int)nCr.size();++i){
        nCr[i][0] = nCr[i][i] = 1;
        for(int j=1;j<i;++j){
            nCr[i][j] = (nCr[i-1][j-1]+nCr[i-1][j])%mod;
        }
    }
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        cout<<nCr[n+k-1][n-1]<<endl;
    }
    return 0;
}
