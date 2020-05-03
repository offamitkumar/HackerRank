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
#define MAXN (int)1e5+100
#define LSB(I) ((I)&(-I))
array<int,MAXN>temp , ftree;

void update(int index , int value , int n){
    while(index<=n){
        ftree[index]+=1;
        index+=(LSB(index));
    }
}

int getSum(int index){
    int sum{};
    while(index>0){
        sum+=ftree[index];
        index-=LSB(index);
    }
    return sum;
}

int getans(int n){
    int ans{};
    for(int i=n;i>=1;--i){
        ans+=getSum(temp[i]);
        update(temp[i],1 , n);
    }
    return ans;
}

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t; cin>>t;
    while(t--){
        fill(ftree.begin() , ftree.end() , 0);
        fill(temp.begin() , temp.end() , 0);
        int n; cin>>n;
        bool possible = true;
        for(int x,i=1;i<=n;++i){
            cin>>x;
            temp[i] = x;
            if(x>i)
                possible&=(abs(x-i)<=2);
        }
        if(possible){
            cout<<getans(n)<<'\n';
        }else{
            cout<<"Too chaotic"<<'\n';
        }
    }
    return 0;
}
