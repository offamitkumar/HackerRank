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
bool check(vector<int>&v , int Size){
    int current{};
    for(int i=0;i<(int)v.size();++i){
        if(current+v[i] > Size){
            return false;
        }
        current+=v[i];
        if(current==Size){
            current = 0;
        }
    }
    return true;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; cin>>n;
    vector<int>v(n);
    int sum{};
    for(int i=0;i<n;++i){
        cin>>v[i];
        sum+=v[i];
    }
    set<int>ans;
    for(int i=1;i*i<=sum;++i){
        if(sum%i==0){
            if(check(v,i)){
                ans.insert(i);
            }
            if(check(v,sum/i)){
                ans.insert(sum/i);
            }
        }
    }
    for(auto &itr:ans){
        cout<<itr<<' ';
    }
    return 0;
}
