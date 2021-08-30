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
        int left , right; cin >> left >> right; 
        int counter{}; 
        while (left != right) {
            ++counter; 
            left>>=1ll;
            right>>=1ll;
        }
        cout << (right <<= counter) << '\n'; 
    }
    return 0;
}
