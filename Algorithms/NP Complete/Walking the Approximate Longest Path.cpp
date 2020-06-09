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

  #include <bitset>
//  #include <tuple>
//  #include <queue>
//  #include <stack>
  #include <vector>
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
const int MAXN = (int)1e5+100;
const int MOD = (int)1e5+100;
bitset<100000>visited;
vector<int>cheating_ans;
vector<int>in_deg(MAXN);
vector<int>res;
vector<vector<int>>graph;
int degrade_factor = 90000;
bool err = false;
void dfs(int n){
    if(degrade_factor < 1 ||(graph.size() > 100 && cheating_ans.size() > graph.size()/2) ){
        return ;
    }
    res.push_back(n);
    visited[n] = true;
    if(rand()&1)
        --degrade_factor;
    for(auto&itr:graph[n]){
        if(!visited[itr]){
            dfs(itr);
        }
    }
    if(cheating_ans.size() < res.size()){
        cheating_ans = res; 
    }
    visited[n] = false;
    res.pop_back();
    return ;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    int n,m; scanf("%d%d",&n,&m);
    graph.resize(n+1);
    visited.reset();
    int node = -1;
    for(int i=0;i<m;++i){
        int u,v; scanf("%d%d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    srand(time(NULL));
    for(int i=1;i<=min(10,n) && degrade_factor;++i){
        if(rand()&1)
            dfs(i);
    }
    puts("");
    printf("%d\n",(int)cheating_ans.size());
    for(auto&itr:cheating_ans){
        printf("%d ",itr);
    }
    puts("");
//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
