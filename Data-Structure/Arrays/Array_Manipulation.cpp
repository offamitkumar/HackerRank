#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree< // find_by_order & order_of_key
        int ,
        null_type ,
        less<int> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
#define MAXN (int)1e7+100
long long arr[MAXN] = {0};
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n , m; cin >> n>> m;
    for(auto i = 0; i<m; ++i){
        int a , b, k; cin>>a>>b>>k;
        arr[a]+=k;
        arr[b+1]-=k;
    }
    long long ans{};
    for(auto i=1; i<n+10;++i){
        arr[i]+=arr[i-1];
        ans = max(ans , arr[i]);
    }
    cout<<ans<<'\n';
    return 0;
}
