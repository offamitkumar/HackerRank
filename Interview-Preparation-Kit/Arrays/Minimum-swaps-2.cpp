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

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; cin>>n;
    vector<int>v(n+1);
    int swap_counter{};
    for(int i=1;i<=n;++i){
        cin>>v[i];
    }
    for(int i=1;i<=n;++i){
        int cycle_size{};
        int current = abs( v[i] );
        while(v[current]>0 && current != i){
            ++cycle_size;
            v[current] = -v[current];
            current = abs(v[current]);
        }
        v[current] =-abs(v[current]);
        swap_counter+=cycle_size;
    }
    cout<<swap_counter<<'\n';
    return 0;
}
