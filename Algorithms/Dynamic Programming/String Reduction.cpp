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
    int t; cin >> t; 
    while (t--) {
        string s; cin >> s; 
        const int &n = s.size();
        vector<int>v(300); 
        for (auto&itr:s) {
            v[itr]++;
        }
        if (v['a']==n || v['b']==n || v['c']==n) {
            cout << n << '\n'; 
        } else if ((v['a']%2==v['b']%2) && (v['b']%2==v['c']%2)) {
            cout << 2 << '\n'; 
        } else {
            cout << 1 << '\n'; 
        }
    }
    return 0;
}
