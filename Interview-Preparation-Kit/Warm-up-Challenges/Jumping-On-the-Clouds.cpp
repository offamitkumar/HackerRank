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
#define MAXN 104
int arr[MAXN];
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
        if(arr[i]==1){
            arr[i]=INT_MIN;
        }else{
            arr[i] = INT_MAX;
        }
    }
    arr[0]=0;
    for(int i=0;i<n;++i){
        if(arr[i]!=INT_MIN){
            for(auto&itr:{1,2}){
                if(arr[i+itr]!=INT_MIN){
                    arr[i+itr] = min(arr[i+itr] , arr[i]+1);
                }
            }
        }
    }
    cout<<arr[n-1]<<'\n';
    return 0;
}
