//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

//  #include <iostream>
  #include <algorithm>
//  #include <string>
//  #include <sstream>
//  #include <fstream>
//  #include <iomanip>
//  #include <chrono>
//  #include <numeric>
  #include <utility>

//  #include <bitset>
//  #include <tuple>
//  #include <queue>
//  #include <stack>
//  #include <vector>
//  #include <array>
//  #include <unordered_map>
//  #include <unordered_set>
  #include <set>
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

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    int n, o; scanf("%d %d",&n,&o);
    int qr , qc; scanf("%d %d",&qr, &qc);
    set<pair<int,int>>s; 
    while(o--){
        int x,y; scanf("%d %d",&x,&y);
        s.insert(make_pair(x,y));
    }
    int counter{};
    int a , b; a = qr,b = qc;
    while(a+1<=n && s.find(make_pair(a+1,b))==s.end()){
        ++counter;
        ++a;
    }
    a = qr , b = qc;
    while(b+1<=n && s.find(make_pair(a,b+1))==s.end()){
        ++counter;
        ++b;
    }
    a = qr , b = qc;
    while(a-1>0 && s.find(make_pair(a-1,b))==s.end()){
        ++counter;
        --a;
    }
    a = qr , b = qc;
    while(b-1>0 && s.find(make_pair(a,b-1))==s.end()){
        ++counter;
        --b;
    }


    a = qr , b = qc;
    while(a+1<=n && b+1<=n && s.find(make_pair(a+1,b+1))==s.end()){
        ++counter;
        ++a;
        ++b;
    }

    a = qr, b = qc;
    while(a-1>0 && b-1>0 && s.find(make_pair(a-1,b-1))==s.end()){
        ++counter;
        --a;
        --b;
    }

    a = qr , b = qc;
    while(a-1>0 && b+1<=n && s.find(make_pair(a-1,b+1))==s.end()){
        ++counter;
        --a;
        ++b;
    }


    a = qr , b = qc;
    while(a+1<=n && b-1>0 && s.find(make_pair(a+1,b-1))==s.end()){
        ++counter;
        ++a;
        --b;
    }
    printf("%d\n",counter);

//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
