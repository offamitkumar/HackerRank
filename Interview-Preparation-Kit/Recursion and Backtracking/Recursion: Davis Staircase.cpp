#include <bits/stdc++.h>

using namespace std;

#define MOD (int)1e9+7
// Complete the stepPerms function below.
map<int , int>dp;
int stepPerms(int n) {
     if(dp.find(n)!=dp.end())
         return dp[n];
    if(n<0){
        return 0;
    }
    if(n==1 || n ==0){
        return 1;
    }
    int x = 0;
    x += stepPerms(n-1); 
    x += stepPerms(n-2); 
    x += stepPerms(n-3); 
    dp[n] = x;
    return dp[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
