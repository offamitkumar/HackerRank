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
    int q,op,k; cin >> q; 
    string c{},temp{};
    stack<string>s;
    s.push(c);
    while (q--) {
        cin >> op; 
        switch(op) {
            case 1:
                cin >> temp; 
                c+=temp; 
                s.push(c);
                break; 
            case 2:
                cin >> k; 
                c = c.substr(0,c.length()-k); 
                s.push(c);
                break;
            case 3:
                cin >> k; 
                cout << c[k-1] << '\n'; 
                break;
            case 4:
                s.pop(); 
                c = s.top();
                break;
        }
    }
    return 0;
}
