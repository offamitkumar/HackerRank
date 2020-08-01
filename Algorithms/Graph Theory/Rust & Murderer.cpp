// for optimization just consider only those nodes which are not visited till now 
// and not neighbour of vertex on which we are standing now. 
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<unordered_set<int>>graph;
unordered_set<int>not_visited;
unordered_set<int>added;
vector<int>dist;
int n , m; 
void bfs(int start){
    dist[start] = 0;
    queue<int>q; 
    q.push(start); 
    for(int i=1; i<=n;++i){
        if(i == start)continue;
        not_visited.insert(i);
    }
    while(!q.empty()){
        int node = q.front(); q.pop(); 
        vector<int>e; // store the node which are visited in this turn and will be removed 
        // from the non-visited node list. Because removing node simultaneously gave seg-fault error.
        for(auto&itr:not_visited){
            if(graph[node].find(itr)!=graph[node].end()){
                continue;
            }
            dist[itr] = dist[node] + 1; 
            if(added.find(itr)==added.end()){
                q.push(itr);
            }
            e.push_back(itr);
        }
        for(auto&itr:e){
            not_visited.erase(itr);
        }
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
    int t; cin >> t; 
    while(t--){
        graph.clear();
        dist.clear();
        not_visited.clear();
        cin >> n >> m; 
        dist.resize(n+1 , INT_MAX);
        graph.resize(n+1); 
        for(int i=0;i<m;++i){
            int x, y; cin >> x >> y;
            graph[x].insert(y);
            graph[y].insert(x);
        }
        int start; cin >> start; 
        bfs(start); 
        for(int i=1;i<=n;++i){
            if( i == start ) continue;
            cout << dist[i] << ' ';
        }
        cout << '\n'; 
    }
    return 0;
}
