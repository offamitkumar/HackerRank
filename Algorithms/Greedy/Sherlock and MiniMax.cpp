#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int fun(vector<int>&v ,int a) {
    int temp{INT_MAX}; 
    for (auto&itr:v) {
        temp = min(temp , abs(itr-a)); 
    }
    return temp;
}
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
    for (auto&itr:v) cin >> itr; 
    int l, r; cin >> l >> r; 
    sort(v.begin(), v.end()); 
    int ans{0}, min_f{INT_MIN}; 
    int a = fun(v,l); 
    if (a > min_f) {
        min_f = a; 
        ans = l;
    }
    a = fun(v,r); 
    if ( a > min_f) {
        min_f = a; 
        ans = r; 
    }
    for (int i=0; i+1 < v.size(); ++i) {
        int mid = (v[i] + v[i+1]) / 2ll ; 
        if (mid >= l && mid <= r) {
            int temp = min(abs(mid-v[i]) , abs(v[i+1]-mid)); 
            if (temp > min_f) {
                min_f = temp; 
                ans= mid; 
            }
            if (temp == min_f) {
                ans = min(ans , mid); 
            }
        }
    }
    cout << ans << '\n'; 
    return 0;
}
