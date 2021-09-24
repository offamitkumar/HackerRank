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
    vector<int>v(n); 
    for (auto&itr:v) {
        cin >> itr; 
    }
    sort(v.begin(),v.end()); 
    int counter{};
    for (int i=0; i<n;) {
        int end = v[i]+4; 
        while (i<n && v[i] <=end) {
            ++i; 
        }
        ++counter; 
    }
    cout << counter << '\n'; 
    return 0;
}
