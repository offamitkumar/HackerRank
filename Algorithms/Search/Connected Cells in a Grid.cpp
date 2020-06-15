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
const int MAXN = (int)22;
const int MOD = (int)1e9+7;
int n, m; 
int grid[MAXN][MAXN];
int visited[MAXN][MAXN];

array<int,8>X{-1,-1,-1,0,0 ,1,1,1};
array<int,8>Y{-1, 0, 1,1,-1,1,-1,0};

bool check(int x, int y ){
    if( x<0 || y < 0 || x >= n || y >= m || visited[x][y] == 1 || grid[x][y] == 0 ){
        return false;
    }
    return true;
}
int best_ans{};
int counter{};
void dfs(int x , int y){
    ++counter;
    visited[x][y] = true;
    for(int i=0;i<8;++i){
        int tempx = x+X[i];
        int tempy = y+Y[i];
        if(check(tempx , tempy)){
            dfs(tempx , tempy);
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

    cin >> n >> m; 
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin >> grid[i][j];
            visited[i][j] = 0;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!visited[i][j] && grid[i][j]==1){
                counter = 0;
                dfs(i,j);
                best_ans = max(best_ans , counter);
            }
        }
    }
    cout << best_ans << '\n'; 

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
        << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
        << " ms" << '\n'; 
#endif 
    return 0;
}
