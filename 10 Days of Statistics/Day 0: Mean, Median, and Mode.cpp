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
    vector<double>v(n); 
    map<double,int>f;
    double v1{} , v2{};
    for(auto&ite:v){
        cin >> ite ;
        f[ite]++;
        if(f[ite]>v2){
            v1 = ite;
            v2 = f[ite];
        }
        if(f[ite]==v2){
            v1 = min(v1 , ite);
        }
    }
    sort(v.begin() , v.end()); 
    cout << fixed << setprecision(1);
    cout << double(accumulate(v.begin() , v.end() , 0ll)) / n << '\n'; 
    if(int(n)&1){
        cout << v.at(n/2) << '\n'; 
    }else{
        cout << (v.at(n/2) + v.at(n/2-1))/2.0f << '\n'; 
    }
    cout << v1 << '\n'; 
    return 0;
}
