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
    double total{};
    for(auto&itr:v){
        cin >> itr;
    }
    double ans{}; 
    for(int i=0; i<n;++i){
        double x; cin >> x; 
        total+=x;
        ans+= (x* v.at(i)); 
    }
    cout << fixed << setprecision(1) << ans / total << '\n'; 
    return 0;
}
