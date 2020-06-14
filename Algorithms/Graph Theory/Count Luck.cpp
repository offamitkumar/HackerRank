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
array<int,4>X{-1,1,0,0};
array<int,4>Y{0,0,-1,1};

vector<string>graph;
vector<vector<bool>>visited;
vector<vector<int>>dist;
pair<int,int> start , end_;
int n, m;

bool check(int x, int y){
    if(x<0 || y<0 || x >= n || y>=m || visited[x][y] == true || graph[x][y]=='X' )
        return false;
    return true;
}
void bfs(void){
    queue<pair<int,int>>q; q.push(start);
    visited[start.first][start.second] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // count unvisited nodes 
        int cost = 0;
        int unvistied_node = 0;
        for(int i=0; i<4; ++i){
            int tempx = x+X[i];
            int tempy = y+Y[i];
            if(check(tempx , tempy)){
                ++unvistied_node;
            }
        }
        cost = (unvistied_node >=2);
        for(int i=0; i<4; ++i){
            int tempx = x+X[i];
            int tempy = y+Y[i];
            if(check(tempx , tempy)){
                visited[tempx][tempy] = true;
                q.push(make_pair(tempx,tempy));
                dist[tempx][tempy] = dist[x][y] + cost;
            }
        }

    }
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

    int t; cin >> t;
    while(t--){
        cin >> n >> m ; 
        graph.clear();
        visited.clear();
        dist.clear();
        visited.assign(n , vector<bool>(m,false));
        dist.assign(n , vector<int>(m,0));
        graph.resize(n);
        for(int i=0;i<n;++i){
            cin >> graph[i];
            for(int j=0;j<m;++j){
                if(graph[i][j]=='M'){
                    start = make_pair(i,j);
                }else if(graph[i][j]=='*'){
                    end_ = make_pair(i,j);
                }
            }
        }
        bfs();
        int M; cin >> M;
        if(dist[end_.first][end_.second] == M){
            cout <<  "Impressed"; 
        }else{
            cout << "Oops!";
        }
        cout << '\n'; 
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
