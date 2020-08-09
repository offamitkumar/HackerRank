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
    while(t--){
        vector<int>cost(1001000 , INT_MAX);
        int n; cin >> n; 
        cost[n] = 0;
        int counter{};
        queue<int>q; 
        q.push(n);
        while(q.front() != 0){
            n = q.front(); 
            q.pop();
            ++counter;
            if(cost[n-1] > cost[n]+1){
                q.push(n-1);
                cost[n-1] = cost[n]+1;
            }
            if(n-1==0){
                break;
            }
            for(int i=2; i*i<=n; ++i){
                if(n%i==0){
                    if(cost[max(i,n/i)]> cost[n]+1){
                        q.push(max(i , n/i));
                        cost[max(i,n/i)] = cost[n]+1;
                    }
                }
            }
        }
        cout << cost[0] << '\n'; 
    }
    return 0;
}
