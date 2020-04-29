#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
#define mod 1000000007



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int s; cin>>s;
    string ss; cin>>ss;
    int current_height{},vallyCounter{};
    bool isTrueVally=true; // this will tell us whether we have seen the 
    // sea level again or not , after stepping down
    for(auto&itr:ss){
        current_height+=((itr=='U')?1:-1);
        vallyCounter+=(isTrueVally && current_height==-1);
        if(current_height>=0){
            isTrueVally = true;
        }else{
            isTrueVally = false;
        }
    }
    cout<<vallyCounter<<endl;

    return 0;
}
