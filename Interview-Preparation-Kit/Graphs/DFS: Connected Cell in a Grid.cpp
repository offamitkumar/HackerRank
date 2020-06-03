#include <bits/stdc++.h>

using namespace std;
vector<vector<bool>>visited;
int largestArea = 0;
int tempArea=0;
void dfs(vector<vector<int>>&grid,int x,int y){
    if(x>=(int)grid.size() || y>=grid[0].size() || x<0 || y<0 || grid[x][y] == 0 || visited[x][y]==true){
        return ;
    }
    tempArea++;
    visited[x][y] =true;
    dfs(grid,x-1,y-1);
    dfs(grid,x+1,y+1);
    dfs(grid,x-1,y);
    dfs(grid,x,y-1);
    dfs(grid,x,y+1);
    dfs(grid,x+1,y);
    dfs(grid,x-1,y+1);
    dfs(grid,x+1,y-1);
}
// Complete the maxRegion function below.
int maxRegion(vector<vector<int>> grid) {
    largestArea = 0;
    visited.assign(grid.size(),vector<bool>(15,false));
    for(int i=0;i<(int)grid.size();++i){
        for(int j=0;j<(int)grid[0].size();++j){
            if(grid[i][j]==1 && (visited[i][j]==false)){
                tempArea = 0;
                dfs(grid,i,j);
                largestArea=max(largestArea,tempArea);
            }
        }
    }
    return largestArea;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    fout << res << "\n";

    fout.close();

    return 0;
}
