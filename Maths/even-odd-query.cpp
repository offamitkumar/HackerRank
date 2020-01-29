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
    int n; cin>>n;
    vector<int>v(n);
    for(auto &itr:v){
        cin>>itr;
    }
    cin>>n;
    while(n--){
        int x,y;cin>>x>>y;
        x--,y--;
        if(x==y){
            if(v[x]&1){
                cout<<"Odd";
            }else{
                cout<<"Even";
            }
        }else if(v[x+1]==0){
            cout<<"Odd";
        }else{
            if(v[x]&1){
                cout<<"Odd";
            }else{
                cout<<"Even";
            }

        }
        cout<<endl;
    }

    return 0;
}
