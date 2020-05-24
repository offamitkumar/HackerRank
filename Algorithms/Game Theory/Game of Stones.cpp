#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfStones function below.
vector<bool>dp(110); // tells whether current position is loosing or winning
bool isCalculatedBefore = false;
void preCalculate(void) {
    isCalculatedBefore = true;
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    dp[4]=1; // give 3 and reach 1 
    dp[5]=1;
    for( int i=6;i<=101;++i ){
        if((!dp[i-2])||(!dp[i-5])||(!dp[i-3])){
            dp[i]=1;
        }else{
            dp[i]=0;
        }
    }
}
string gameOfStones(int n) {
    /*
     * O(1)
     *
     *

    if(n%7==0 || n%7==1){
        return "Second";
    }else{
        return "First";
    }


    */
    preCalculate();
    if(dp[n]){
        return "First";
    }else{
        return "Second";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = gameOfStones(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
