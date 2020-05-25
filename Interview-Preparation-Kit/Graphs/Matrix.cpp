#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool compare(vector<int>&a , vector<int>&b){
    return a[2] > b[2];
}
const int total_nodes = (int)1e5+10;
int parent[total_nodes];
int bad_nodes_with_parent[total_nodes];
bool is_bad[total_nodes];
int find_parent(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find_parent(parent[node]);
}
// Complete the minTime function below.
int minTime(vector<vector<int>> roads, vector<int> machines) {
    sort(roads.begin() , roads.end() , compare);
    iota(parent , parent+total_nodes, 0);
    memset(bad_nodes_with_parent , 0, sizeof(bad_nodes_with_parent));
    memset(is_bad , false , sizeof(is_bad));
    for(auto&itr:machines)
        is_bad[itr]=true;
    int total_cost{};
    for(auto&itr:roads){
        int u = itr[0];
        int v = itr[1];
        int w = itr[2];
        int u_parent = find_parent(u);
        int v_parent = find_parent(v);
        if (is_bad[u]) {
            if(is_bad[v] || (bad_nodes_with_parent[v_parent]>0) ) {
                total_cost+=w;
            }else{
                parent[v_parent] = u_parent;
                bad_nodes_with_parent[u_parent]++;
                bad_nodes_with_parent[v_parent]++;
            }
        } else if (is_bad[v]){
            if(is_bad[u] || (bad_nodes_with_parent[u_parent]>0 ) ) {
                total_cost+=w;
            }else{
                parent[v_parent] = u_parent;
                bad_nodes_with_parent[u_parent]++;
                bad_nodes_with_parent[v_parent]++;
            }
        } else {
            if(bad_nodes_with_parent[u_parent]>0 && bad_nodes_with_parent[v_parent]>0){
                total_cost+=w;
            }else{
                int u_B = bad_nodes_with_parent[u_parent];
                int v_B = bad_nodes_with_parent[v_parent];
                parent[v_parent] = u_parent;
                bad_nodes_with_parent[u_parent] = max(u_B , v_B);
                bad_nodes_with_parent[v_parent] = max(u_B , v_B);
            }
        }
    }
    return total_cost;
}

int main() {
    int n , k; cin>>n>>k;
    vector<vector<int>>v(n-1,vector<int>(3));
    for(int j=0;j<n-1;++j){
        for(int i=0;i<3;++i){
            cin>>v[j][i];
        }
    }
    vector<int>bad(k);
    for(auto&itr:bad){
        cin>>itr;
    }
    cout<<minTime(v , bad)<<'\n';
    return 0;
}

