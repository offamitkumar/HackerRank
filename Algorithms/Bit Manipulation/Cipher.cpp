#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int Int(char ch) {
    return ch-'0';
}
char Char(int i) {
    return i+'0'; 
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n, k; cin >> n >> k; 
    string s; cin >> s; 
    if (n>k)
        n = (s.size()-k+1);
    string ans;
    int x=0;
    ans.push_back(s[0]); 
    for (int i=1; i<min(n,k); ++i) {
        ans.push_back(Char(Int(s[i])^Int(s[i-1])));
    }
    for(int i=k; i<n; ++i) {
        int temp = k-1 , j=i-1; 
        int a{};
        while (temp--){ 
            a^=Int(ans[j--]);
        }
        ans.push_back(Char(a^Int(s[i])));
    }
    cout << ans << '\n'; 
    return 0;
}
