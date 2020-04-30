#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#include <sstream>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
using namespace __gnu_pbds;
typedef tree< // find_by_order & order_of_key
        int ,
        null_type ,
        less<int> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    string s; cin>>s;
    long long n; cin>>n;
    --n;
    long long div = n/(long long)s.size();
    long long mod = n%(long long)s.size();
    long long ans{};
    long long a_counter{};
    for(long long  i=0;i<(long long )s.size();++i){
        a_counter+=(s[i]=='a');
        if(i==mod){
            ans+=a_counter;
        }
    }
    cout<<ans+a_counter*div<<'\n';
    return 0;
}
