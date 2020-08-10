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
    double mean{};
    for(auto&itr:v){
        cin >> itr;
        mean += itr;
    }
    mean = mean/n;
    double sd{};
    for(auto&itr:v){
        sd += ((itr-mean)*(itr-mean));
    }
    sd /=n; 
    cout << fixed << setprecision(1);
    cout << sqrt(sd) << '\n'; 
    return 0;
}
