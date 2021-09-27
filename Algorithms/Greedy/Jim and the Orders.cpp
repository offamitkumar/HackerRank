#include <bits/stdc++.h>
using namespace std;
#define int int64_t
bool compare(pair<int,int>&a, pair<int,int>&b) {
    if (a.first  == b.first) {
        return a.second < b.second;
    } else {
        return a.first < b.first; 
    }
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
    vector<pair<int,int>>v(n); 
    for (int i=0; i<n; ++i) {
        int x,y; cin >> x >> y; 
        v[i].first = x+y; 
        v[i].second = i;
    }
    sort(v.begin(), v.end(), compare); 
    for (auto&itr:v) {
        cout << itr.second + 1 << ' ';
    }
    cout << '\n'; 
    return 0;
}
