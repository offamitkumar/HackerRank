#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
const int MAXN = 1e5+100;
array<int, MAXN>parent;
int find_parent(int node){
    if( parent[node] == node ){ 
        return node;
    }else{
        return parent[node] = find_parent(parent[node]);
    }
}
// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    iota(parent.begin(), parent.end(),0);
    set<int>lib;
    long long total_cost{};
    for(auto&itr:cities){
        int x = find_parent(itr[0]);
        int y = find_parent(itr[1]);
        if(x != y){
            parent[y] = x;
            total_cost+=c_road;
        }
    }
    for(int i=1; i<=n; ++i){
        int x = find_parent(i);
        if(lib.find(x)==lib.end()){
            lib.insert(x);
            total_cost+=c_lib;
        }
    }
    return min({total_cost,(long long )c_lib*n});
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
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
