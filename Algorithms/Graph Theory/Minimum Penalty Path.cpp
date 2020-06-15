//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

#include <iostream>
#include <algorithm> 
#include <string> 
//  #include <sstream> 
//  #include <fstream>
//  #include <iomanip> 
#include <chrono> 
#include <numeric>
#include <utility>
#include <functional>

#include <bitset>
#include <tuple>
#include <queue>
#include <stack>
#include <vector>
#include <array>
//  #include <unordered_map>
//  #include <unordered_set>
#include <set>
#include <map>
//  #include <deque>

#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdio>
using namespace std;
using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//                   TypeInfo ,
//                   null_type ,
//                   less<TypeInfo> ,
//                   rb_tree_tag ,
//                   tree_order_statistics_node_update 
//       > ;

void debug_out() { cerr << endl; }
 
template <typename HEAD, typename... TAIL>
void debug_out(HEAD H, TAIL... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef HELL_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif
 

const int MAXM = (int)1e5+100;
const int MAXN = (int)1e3+100;
const int MOD = (int)1e9+7;

vector<vector<pair<int,int>>>edges;
int visited[MAXN][MAXN];


int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 
    memset(visited , false , sizeof(visited));
    int n , m; cin >> n >> m;
    edges.resize(n+1);
    for(int i=0;i<m;++i){
        int u , v , w; cin >> u >> v >> w;
        edges[u].push_back({v,w});
        edges[v].push_back({u,w});
    }
    int start , dest; cin >> start >> dest; 
    queue<int> q;
    q.push(start); q.push(0);
    visited[start][0]= true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        int w = q.front(); q.pop();
        for(int i=0; i< edges[u].size(); ++i){
            int v = edges[u][i].first;
            int W = edges[u][i].second;
            if(!visited[v][w|W]){
                visited[v][W|w] = true;
                q.push(v);
                q.push(W|w);
            }
        }
    }
    for(int i=0;i<=1024;++i){
        if(visited[dest][i]){
            cout << i <<  '\n';;
            return 0;
        }
    }
    cout << -1 << '\n';

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
