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
#define MAXN 30010
array<int,MAXN>parent , com_size;
int find_parent( int current )  {
    if(current == parent[current]){
        return current;
    }

    return parent[current] = find_parent(parent[current]);
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    fill(com_size.begin() , com_size.end() , 0);
    for(int i=0;i<(int)parent.size();++i){
        parent[i] = i;
    }
    int n; cin>>n;
    int max_comp{-1} , min_comp{10000000};
    for(int i=0;i<n;++i){

        int u , v; cin>>u>>v;

        u = find_parent(u);
        v = find_parent(v);

        parent[v] = u;

    }

    for(int i=1;i<=2*n;++i){
        int u = find_parent(i);
        ++com_size[u];
    }
    for(int i=1;i<=2*n;++i){
        max_comp = max(max_comp , com_size[i]);
        if(com_size[i]>1){
            min_comp = min(min_comp , com_size[i]);
        }
    }
    cout<<min_comp<<' '<<max_comp<<'\n';
    return 0;
}
