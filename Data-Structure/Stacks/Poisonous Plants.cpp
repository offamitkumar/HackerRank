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
    vector<int>v(n); for(auto&itr:v) cin >> itr; 
    int mxday{},tday{};
    stack<pair<int,int>>s; 
    for (const auto&itr:v) {
        tday = 0;
        while ((!s.empty()) and s.top().first >= itr) {
            tday = max(tday , s.top().second); 
            s.pop();
        }
        if (!s.empty()) {
            ++tday;
        }else{
            tday = 0;
        }
        mxday = max(mxday , tday);
        s.push(make_pair(itr, tday));
    }
    cout << mxday << '\n'; 
    return 0;
}
