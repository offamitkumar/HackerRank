#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
vector<vector<long long>>graph;
bitset<(long long)1e5+100>visited;
long long Size = 0;
void dfs(long long node){
    visited[node] = true;
    ++Size;
    for(auto&itr:graph[node]){
        if(!visited[itr]){
            dfs(itr);
        }
    }
}
// Complete the journeyToMoon function below.
long long journeyToMoon(long long n, vector<vector<long long>> astronaut) {
    visited.reset();
    long long m = astronaut.size();
    graph.resize(n+1);
    for(auto&itr:astronaut){
        graph[itr[0]].push_back(itr[1]);
        graph[itr[1]].push_back(itr[0]);
    }
    long long total = 0;
    long long comp = 0;
    for(long long i=0;i<n;++i){
        if(!visited[i]){
            dfs(i);
        }
        total += (long long)((long long)comp * (long long)Size);
        comp+=Size;
        Size =(long long) 0;
    }
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    long long n = stoi(np[0]);

    long long p = stoi(np[1]);

    vector<vector<long long>> astronaut(p);
    for (long long i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (long long j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = journeyToMoon(n, astronaut);

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
