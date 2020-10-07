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
    string s; cin >> s;
    map<char,int>f; 
    for (auto&itr:s) {
        f[itr]++;
    }
    int limit = n / 4;
    if (f['A'] == limit && f['T'] == limit && f['C'] == limit && f['G'] == limit) {
        cout << 0 << '\n'; 
    } else {
        int left = 0 , right = 0; 
        int ans = n;
        while (right< n && left <= right) {
            while (right < n && (f['A'] > limit || f['T'] > limit || f['C'] > limit || f['G'] > limit)) {
                f[s[right++]]--;
            }
            while (left < n && f['A'] <= limit && f['T'] <= limit && f['C'] <= limit && f['G'] <= limit) {
                f[s[left++]]++;
            }
            ans =min(ans , right-left+1);
        }
        cout << ans << '\n';
    }
    return 0;
}
