#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
array<int,4>X{-1,1,0,0};
array<int,4>Y{0,0,-1,1};

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    int n = grid.size(); 
    int m = grid[0].size();
    vector<vector<int>> dist(n , vector<int>(m , 0)); 
    auto check = [&](int x, int y) {
        if(x<0 || y<0 || x>=n || y>=n || grid[x][y] == 'X'){
            return false;
        }
        return true;
    };
    queue<pair<int,int>>q; 
    q.push(make_pair(startX , startY));
    while(!q.empty()){
        int tx , ty;
        tie(tx,ty) = q.front(); q.pop();
        for(int i=0;i<4; ++i){
            int x = tx+X[i];
            int y = ty+Y[i];
            while(check(x,y)){
                if(grid[x][y] != '$'){
                    q.push(make_pair(x,y));
                    grid[x][y] = '$';
                    dist[x][y] = dist[tx][ty]+1;
                }else if(dist[x][y] != dist[tx][ty]+1){
                    break;
                }
                x = x+X[i];
                y = y+Y[i];
            }
        }
    }
    return dist[goalX][goalY];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

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
