#include <bits/stdc++.h>
using namespace std;
#define int int64_t
string sol(void) {
    int n, m; cin >> n >> m; 
    vector<string>v(n); 
    for (auto&itr:v) {
        cin >> itr; 
    }
    int a,b; cin >> a >> b; 
    vector<string>p(a); 
    for (auto&itr:p) {
        cin >> itr; 
    }
    for (int i=0; i<n-a+1; ++i) {
        for (int j=0; j<m-b+1; ++j) {
            if (v[i][j] == p[0][0]) {
                bool a1{true};
                for (int k =0; k<a and a1; ++k) {
                    for (int l=0; l<b and a1; ++l) {
                        if (v[i+k][j+l] != p[k][l]) {
                            a1 = false;
                        }
                    }
                }
                if (a1) {
                    return "YES";
                }
            }
        }
    }
    return "NO";
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t; cin >> t; 
    while(t--) {
        cout << sol() << '\n'; 
    }
    return 0;
}
