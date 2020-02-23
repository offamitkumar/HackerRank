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
#include <sstream>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
#define MOD 1000000007
#define MAXM 55
#define MAXN 251
long long arr[MAXN][MAXM];
long long n , m;
vector<long long>v(MAXM);
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>v[i];
    }
    for(int i=0;i<m;++i){
        arr[0][i] = 1;
    }
    // arr[i][j] -> number of ways forming sum equal to i by including j coins
    for(int i=1;i<n+1;++i){
        for(int j=0;j<m;++j){
            long long x = (i-v[j]>=0)?arr[i-v[j]][j]:0;
            long long y = (j>=1)?(arr[i][j-1]):0;
            arr[i][j] = x+y;
        }
    }
    cout<<arr[n][m-1]<<endl;
    return 0;
}
