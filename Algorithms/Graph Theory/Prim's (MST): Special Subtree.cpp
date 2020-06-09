#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {
    vector<int>dist(n+100,INT_MAX);
    vector<bool>visited(n+100,false);
    dist[start] = 0;
    auto getMinNode = [&](void){
        int current_dist = INT_MAX;
        int current_node = -1;
        for(int i=1;i<=n;++i){
            if(current_dist > dist[i] && visited[i] == false){
                current_dist = dist[i];
                current_node = i;
            }
        }
        visited[current_node] = true;
        return current_node;
    };
    int m = edges.size();
    int sum{};
    for(int i=0;i<n;++i){
        int minNode = getMinNode();
        sum+=dist[minNode];
        for(int j=0;j<m;++j){
            const int &start = edges[j][0];
            const int &end = edges[j][1];
            const int &weight = edges[j][2];
            if(start == minNode){
                dist[end] = min(dist[end] ,weight); // mark the nodes, found 
            }
            if(end == minNode){
                dist[start] = min(dist[start] ,weight); // node found 
            }
        }
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int start;
    cin >> start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = prims(n, edges, start);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
