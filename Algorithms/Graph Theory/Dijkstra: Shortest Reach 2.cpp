#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    vector<int>dist(n+3 , 1000000);
    dist[s] = 0;
    int m = edges.size();
    bool relaxed = true;
    for(int i=0; i<=n && relaxed; ++i){
        relaxed = false;
        for(int j=0;j<m;++j){
            const int &start = edges[j][0];
            const int &end = edges[j][1];
            const int &weight = edges[j][2];
            if(dist[end] > dist[start] + weight){
                relaxed = true;
                dist[end] = dist[start] + weight;
            }
            if(dist[start] > dist[end] + weight){
                relaxed = true;
                dist[start] = dist[end] + weight;
            }
        }
    }
    vector<int>ans;
    for(int i=1;i<=n;++i){
        if(i == s)continue;
        if(dist[i]==1000000){
            dist[i] = -1;
        }
        ans.push_back(dist[i]);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = shortestReach(n, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

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
