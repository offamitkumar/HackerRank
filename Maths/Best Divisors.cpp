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
using namespace std;
int dig(string a){
    int suma = 0;
    for(auto &itr:a){
        suma+=(itr-'0');
    }
    return suma;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin>>n;
    set<int>s;
    s.insert(1);
    s.insert(n);
    for(int i=2;i*i<=n;++i ){
        if(n%i==0){
            s.insert(n/i);
            s.insert(i);
        }
    }
    int ans=*s.begin();
    for(auto &itr:s){
        if(dig(to_string(itr))==dig(to_string(ans))){
            ans = min(ans , itr);
        }else if(dig(to_string(itr))>dig(to_string(ans))){
            ans = itr;
        }
    }
    cout<<ans<<endl;
    return 0;
}
