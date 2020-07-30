#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<vector<int>>graph;
vector<int>dist; 
void bfs(int start , int stop){
    dist[start] = 0; 
    queue<int>q; q.push(start); 
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(int i:{1,2,3,4,5,6}){
            int child = i+node;
            if(child>100){
                continue;
            }
            if(graph[child].empty()==false){ // snake or ladder 
                child = graph[child][0];
            }
            if(dist[child] > dist[node]+1){
                q.push(child);
                dist[child] = dist[node]+1;
            }
        }
    }
    return;
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
    while(t--){
        dist.assign(110,INT_MAX);
        graph.assign(110 , vector<int>());
        int n; cin >> n;  
        for(int i=0;i<n;++i){
            int x, y; cin >> x >> y; 
            graph[x].push_back(y);
        }
        cin >> n; 
        for(int i=0;i<n;++i){
            int x, y; cin >> x >> y; 
            graph[x].push_back(y);
        }
        bfs(1,100);
        if(dist[100]==INT_MAX){
            cout << -1 << '\n'; 
        }else{
            cout << dist[100] << '\n'; 
        }
    }
    return 0;
}
