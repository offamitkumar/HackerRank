#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n; cin >> n; 
    vector<int>v(n); 
    for(auto&itr:v){
        cin >> itr; 
    }
    sort(v.begin() , v.end());
    int q1,q2,q3;
    int left, right;
    if(n&1){
        q2 = v.at(n/2);
        left = n/2; 
        right = n/2+1;
    }else{
        q2 = (v.at(n/2) + v.at(n/2-1))/2;
        left = n/2; 
        right = n/2;
    }
    if(left&1){
        q1 = v.at(left/2); 
    }else{
        q1 = (v.at(left/2)+v.at(left/2-1))/2;
    }
    if((n-right)&1){
        q3 = v.at(right+(n-right)/2);
    }else{
        q3 = (v.at(right+(n-right)/2) + v.at(right+(n-right)/2-1))/2;
    }
    cout << q1 << '\n' << q2 << '\n' << q3 << '\n'; 
    return 0;
}
