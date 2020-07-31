#include <bits/stdc++.h>
using namespace std;
#define int int64_t
unordered_map<int , int> parent; 
unordered_map<int , int> circle; 
int find_parent(int node){
    if(parent[node] == node){
        return node;
    }else{
        return parent[node] = find_parent(parent[node]);
    }
}
int Merge(int node1, int node2){
    if(circle[node1] > circle[node2]){
        circle[node1] += circle[node2];
        parent[node2] = node1;
        return circle[node1];
    }else{
        circle[node2] += circle[node1]; 
        parent[node1] = node2;
        return circle[node2];
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
    int q; cin >> q; 
    int largest_group = 0;
    while(q--){
        int x, y;  cin >> x >> y;
        if(parent.find(x)==parent.end()){
            circle[x] = 1;
            parent[x] = x;
        }
        if(parent.find(y)== parent.end()){
            circle[y] = 1;
            parent[y] = y;
        }
        x = find_parent(x); 
        y = find_parent(y); 
        if(x!=y)
            largest_group = max(largest_group , Merge(x, y));
        cout << largest_group << '\n'; 
    }
    return 0;
}
