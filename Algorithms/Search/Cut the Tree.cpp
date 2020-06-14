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
const int MAXN = (int)1e5+100;
const int MOD = (int)1e9+7;

vector<int>dist;
vector<int>weight;
vector<vector<int>>graph;
vector<bool>visited;
int totalWeight{};
int dfs(int node){
    visited[node] = true;
    int cost{};
    for(auto&itr:graph[node]){
        if(!visited[itr]){
            cost+=dfs(itr);
        }
    }
    return weight[node] = cost + dist[node];
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 

    int n; scanf("%d",&n);
    graph.resize(n+1);
    visited.assign(n+1 , false);
    dist.assign(n+1 , 0);
    weight.assign(n+1 , 0);
    for(int i=1; i<=n;++i){
        cin >> dist[i];
        totalWeight+=dist[i];
    }
    for(int i=1; i<n;++i){
        int u,v; cin >> u >> v; 
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1);
    int best = INT_MAX;
    for(int i=1;i<=n;++i){
        int firstTree = totalWeight - weight[i];
        int secondTree = weight[i];
        if(abs(firstTree - secondTree) < best){
            best = abs(firstTree - secondTree);
        }
    }
    cout << best << '\n'; 

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
