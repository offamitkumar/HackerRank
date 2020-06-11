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
  #include <cstring>
//  #include <cmath>
  #include <cassert>
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
const int MAXM = (int)90;
const int MAXN = (int)40;
const int MOD = (int)1e9+7;
int board[MAXN][MAXN];
int grundy[MAXN][MAXN][MAXN][MAXN];
int n; 
bool prime(int x){
    if(x==2 or x==3 or x==5 or x==7){
        return true;
    }
    return false;
}
bool allPrime(int a, int b, int x, int y){
    for(int i = a; i <= x; ++i){
        for(int j=b; j<=y;++j){
            if(!board[i][j]){
                return false;
            }
        }
    }
    return true;
}
int getGrundy(int a , int b , int x, int  y){
    if(grundy[a][b][x][y]!=-1){
        return grundy[a][b][x][y];
    }
    if(allPrime(a,b,x,y)){
        grundy[a][b][x][y] = 0;
        return grundy[a][b][x][y];
    }
    int mex[80];
    for(int i=0;i<80;++i){
        mex[i] = 0;
    }
    for(int i=a+1;i<=x;++i){
        mex[getGrundy(a,b,i-1,y)^getGrundy(i,b,x,y)] = 1;
    }
    for(int i=b+1;i<=y;++i){
        mex[getGrundy(a,b,x,i-1)^getGrundy(a,i,x,y)] = 1;
    }
    for(int i=0;i<80;++i){
        if(!mex[i]){
            grundy[a][b][x][y] = i;
            return i;
        }
    }
    puts("MEX ERROR");
    assert(false);
    return INT_MIN;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                int x; scanf("%d",&x);
                if(prime(x)){
                    board[i][j] = 1;
                }else{
                    board[i][j] = 0;
                }
            }
        }
        memset(grundy,0,sizeof(grundy));
        for(int i=1;i<=31;++i){
            for(int j=1;j<=31;++j){
                for(int k=1;k<=31;++k){
                    for(int l=1;l<=31;++l){
                        grundy[i][j][k][l]=-1;
                    }
                }
            }
        }
        puts(getGrundy(1,1,n,n)? "First" : "Second");
    }

//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
