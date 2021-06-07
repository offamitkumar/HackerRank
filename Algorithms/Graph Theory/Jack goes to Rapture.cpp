#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<int>parent;
vector<pair<int , pair<int,int>>>g; 
bool com(pair<int,pair<int,int>> p1 , pair<int,pair<int,int>>p2) {
    return p1.first < p2.first;
}
int find_parent(int node) {
    if(parent[node] == node) {
        return node; 
    }else {
        return parent[node] = find_parent(parent[node]);
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
    int n, e; cin >> n >> e; 
    parent.resize(n); 
    iota(parent.begin(),parent.end(),0); 
    g.resize(e);
    for(int i=0; i<e; ++i) {
        int u , v , w; cin >> u >> v >> w; 
        --u,--v;
        g[i] = make_pair(w , make_pair(u,v)); 
    }
    sort(g.begin() , g.end(), com); 
    int min_ans{INT_MAX}; 
    for (int i=0; i<e; ++i) {
        int u = g[i].second.first; 
        int v = g[i].second.second; 
        int w = g[i].first; 
        u = find_parent(u); 
        v = find_parent(v); 
        if (u!=v) {
            parent[u] = v; 
        }
        if (find_parent(0) == find_parent(n-1)) {
            min_ans = w; 
            break; 
        }
    }
    if (min_ans == INT_MAX) {
        cout << "NO PATH EXISTS" << '\n'; 
    } else {
        cout << min_ans << '\n'; 
    }
    return 0;
}
