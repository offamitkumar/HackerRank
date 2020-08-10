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
    double n; cin >> n; 
    vector<double>v1(n),v2; 
    for(auto&itr:v1){
        cin >> itr;
    }
    for(int i=0; i<n;++i){
        int f; cin >> f; 
        for(int j =0;j<f; ++j){
            v2.emplace_back(v1[i]);
        }
    }
    sort(v2.begin() , v2.end());
    double q1 , q2 , q3;
    double left , right; 
    n = v2.size();
    if(int(n)&1){
        q2 = v2.at(n/2);
        left = int(n/2-1); 
        right = int(n/2+1);
    }else{
        q2 = double(v2.at(n/2)+v2.at(n/2-1))/(double)2.0f;
        left = n/2;
        right = n/2+1;
    }
    if(int(left)&1){
        q1 = v2.at(left/2);
    }else{
        q1 = (v2.at(left/2) + v2.at(left/2-1)) /2.0f;
    }
    
    if(int(n-right)&1){
        q3 = v2.at(right+(n-right)/2);
    }else{
        q3 = double(v2.at(right+(n-right)/2)+v2.at(right+(n-right)/2-1))/2.0f;
    }
    cout << fixed << setprecision(1);
    cout << q3 - q1 << '\n'; 
    return 0;
}
