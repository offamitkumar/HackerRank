//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

//  #include <iostream>
//  #include <algorithm>
//  #include <string>
//  #include <sstream>
//  #include <fstream>
//  #include <iomanip>
//  #include <chrono>
//  #include <numeric>
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

  #include <climits>
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
const int MAXN = (int)500;
const int MOD = (int)1e9+7;
int n, m; 
long long dist[MAXN][MAXN];

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    scanf("%d %d",&n,&m);
    for(int i=0;i<MAXN;++i){
        for(int j=0;j<MAXN;++j){
            dist[i][j] = INT_MAX;
            dist[i][i] = 0;
            dist[j][j] = 0;
        }
    }
    for(int i=0;i<m;++i){
        int u,v,w; scanf("%d %d %d",&u,&v,&w);
        dist[u][v] = w;
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n; ++i){
            for(int j=1;j<=n;++j){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    scanf("%d",&m);
    while(m--){
        int a,b; scanf("%d %d",&a,&b);
        printf("%lld\n",(dist[a][b]==INT_MAX) ? -1ll : dist[a][b]);
    }
//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
