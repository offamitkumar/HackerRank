//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

  #include <iostream>
  #include <algorithm>
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
const int MOD = (int)1e9+7;
struct Node{
    long long F , S , D;
};
bool comparator( const Node&a , const Node&b ){ 
    return abs(a.D) > abs(b.D);
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    long long t; scanf("%lld",&t);
    while(t--){
        long long n; scanf("%lld",&n);
        vector<long  long>A(n);
        for(auto&itr:A)
            cin >> itr;
        vector<Node>v(n);
        for(long long i=0;i<n;++i){
            long long x; cin >> x;
            v[i].F = A[i];
            v[i].S = x;
            v[i].D = (A[i] + x);
        }
        sort(v.begin() , v.end() ,comparator );
        long long playerOne{} , playerTwo{};
        bool trun = true;
        for(auto&itr:v){
            if(trun){
                playerOne+=abs(itr.F);
                trun = false;
            }else{
                playerTwo+=abs(itr.S);
                trun = true;
            }
        }
        if(playerTwo == playerOne){
            puts("Tie");
        }else if(playerOne > playerTwo){
            puts("First");
        }else{
            puts("Second");
        }
    }

//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
