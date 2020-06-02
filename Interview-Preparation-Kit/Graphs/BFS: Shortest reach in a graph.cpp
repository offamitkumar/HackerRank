#include <cmath>
#include <cstdio>
#include <vector>
#include <bitset>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
    vector<vector<int>>graph;
    static const int cost = 6;
    int N;
    vector<int>dist;
    bitset<2000>visited;
    public:
        Graph(int n) {
            graph.resize(n);
            N = n;
        }
    
        void add_edge(int u, int v) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            dist.clear();
            visited.reset();
            dist.assign(N,-1);
            dist[start] = 0;
            queue<int>q; 
            visited[start] = true;
            q.push(start);
            while(!q.empty()){
                int current_node = q.front();q.pop();
                for(auto&itr:graph[current_node]){
                    if(!visited[itr]){
                        if(dist[itr]==-1){
                            dist[itr] = 0;
                        }
                        dist[itr] += dist[current_node] + cost;
                        visited[itr] =true;
                        q.push(itr);
                    }
                }
            }
            return dist;
        }
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
