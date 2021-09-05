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
        int n; cin >> n; 
        int ans{};
        for (int i=1; i<=n; ++i) {
            int x; cin >> x;
            if ((i*(n-i-1))&1) {
                ans^= x;
            }
        }
        cout << ans << '\n'; 
    }
    return 0;
}
