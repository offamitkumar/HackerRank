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
    int n , d; 
    cin>>n>>d;
    int *arr= new int[n];
    int rotatation = __gcd(n,d);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    for(int k=0;k<rotatation;++k){
        int i=k,j=k,temp=arr[i];
        for(;(j+d)%n!=i;j=(j+d)%n){
            arr[j]=arr[(j+d)%n];
        }
        arr[j] = temp;
    }
    for(int i=0;i<n;++i){
        cout<<arr[i]<<' ';
    }

    return 0;
}
