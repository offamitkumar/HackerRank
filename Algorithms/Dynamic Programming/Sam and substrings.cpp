#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int mod = (int)1e9+7;
int Int(char c) {
    return c-'0'; 
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    string s; cin >> s; 
    vector<int>dp(s.length()+100); 
    dp[0] = Int(s[0]); 
    for(int i=1; i<s.length(); ++i) {
        dp[i] = (dp[i-1]*10ll)%mod; 
        dp[i] = (dp[i]+(Int(s[i])*(i+1ll))%mod)%mod;
    }
    for(int i=1; i<s.length(); ++i) {
        dp[i] = (dp[i]%mod + dp[i-1]%mod)%mod; 
    }
    cout << dp[s.length()-1] << '\n'; 
    return 0;
}
