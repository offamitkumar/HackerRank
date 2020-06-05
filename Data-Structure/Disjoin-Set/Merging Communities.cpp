//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

  #include <iostream>
//  #include <algorithm>
//  #include <string>
//  #include <sstream>
//  #include <fstream>
//  #include <iomanip>
//  #include <chrono>
  #include <numeric>
//  #include <utility>

//  #include <bitset>
//  #include <tuple>
//  #include <queue>
//  #include <stack>
//  #include <vector>
//  #include <array>
//  #include <unordered_map>
//  #include <unordered_set>
//  #include <set>
//  #include <map>
//  #include <deque>

//  #include <climits>
//  #include <cstring>
//  #include <cmath>
//  #include <cassert>
#include <cstdio>
using namespace std;
//  using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//          TypeInfo ,
//          null_type ,
//          less<TypeInfo> ,
//          rb_tree_tag ,
//          tree_order_statistics_node_update 
//  > ;
const int MAXM = (int)1e5+100;
const int MAXN = (int)2e5+1000;
const int MOD = (int)1e5+100;
long long parent[MAXN];
long long arr_s[MAXN];
void pre(const long long &n){
    for(long long i=0;i<=n+10;++i){
        parent[i] = i;
        arr_s[i] = 1;
    }
}
long long find_parent(long long u){
    if(parent[u] == u){
        return u;
    }
    return parent[u] = find_parent(parent[u]);
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    long long n,q; cin >> n >> q;
    char c; 
    pre(n);
    while(q--){
        cin >> c;
        if(c == 'Q'){
            long long num; cin >> num;
            long long u = find_parent(num);
            printf("%lld\n",arr_s[u]);
        }else{
            long long n1,n2; cin >> n1 >> n2;
            long long u = find_parent(n1);
            long long v = find_parent(n2);
            if(u == v){
                continue;
            }
            if(arr_s[u] > arr_s[v]){
                parent[v] = u;
                arr_s[u] += arr_s[v];
                arr_s[v] = 0;
            }else{
                parent[u] = v;
                arr_s[v] += arr_s[u];
                arr_s[u] =0;
            }
        }
    }
//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
