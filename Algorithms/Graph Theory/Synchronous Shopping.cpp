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
  #include <vector>
//  #include <array>
//  #include <unordered_map>
//  #include <unordered_set>
  #include <set>
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
const int MAXN = (int)1e4+10;
const int MOD = (int)1e9+7;
// struct Node{
//     int u , v, w;
// };
int n, m, k; 
int total_fish;
int fish[MAXN];
vector<vector<pair<int,int>>>graph;
// v[start][end][dist]
int dist[MAXN][MAXN];
/// dist[start][fish_we_can_have] = min_cost possible 

set<vector<int>>pq; // priority queue {cost , start_point , end_point}
void Push(int cost , int start , int end_){
    if(dist[start][end_] < cost){
        return ;
    }
    vector<int>temp_v = {dist[start][end_], start , end_};
    auto itr = pq.find(temp_v);
    if(itr != pq.end()){
        pq.erase(itr);
    }
    temp_v[0] = cost;
    dist[start][end_] = cost;
    pq.insert(temp_v);
    return ;
}
void pre(void) {
    for(int i=0;i<=n;++i){
        for(int j=0;j<=total_fish;++j){
            dist[i][j] = INT_MAX;
        }
    }
    return;
}
void dij(void){
    pre();
    Push(0, 1, fish[1]);
    while(!pq.empty()){
        auto front_ele = pq.begin();
        int cost = (*front_ele)[0];
        int start =(*front_ele)[1];
        int end_ = (*front_ele)[2];
        pq.erase(pq.begin());
        for(auto &itr:graph[start]){
            Push(cost + itr.second ,itr.first ,end_|fish[itr.first] );
        }
    }
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    scanf("%d %d %d",&n,&m, &k);
    total_fish = (1 << k);
    graph.resize(n+100);
    for(int i = 1;i<=n; ++i){
        int i_fish; scanf("%d" , &i_fish);
        fish[i]=0;
        for(int j=0;j<i_fish; ++j){
            int x; scanf("%d",&x);
            fish[i]|=(1<<(x-1));
        }
    }
    for(int i=0;i<m;++i){
        int u , v , w; scanf("%d %d %d",&u,&v,&w);
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }
    dij();
    int res = INT_MAX;
    for(int i=0;i<total_fish;++i){
        for(int j=i;j < total_fish; ++j){
            if((i|j) == total_fish-1){
                int temp ; 
                if(dist[n][i] > dist[n][j]){
                    temp = dist[n][i];
                }else {
                    temp = dist[n][j];
                }
                res = min(res , temp);
            }
        }
    }
    printf("%d\n",res);
//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
