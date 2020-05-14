#include <bits/stdc++.h>

using namespace std;
int matrix[5010][5010];
// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    memset(matrix , 0 , sizeof(matrix));
    for(int i=1;i<=(int)s1.size();++i){
        for(int j=1;j<=(int)s2.size();++j){
            if(s1[i-1] == s2[j-1]){
                matrix[i][j] = matrix[i-1][j-1]+1;
            }else{
                matrix[i][j] = max(matrix[i-1][j] , matrix[i][j-1]);
            }
        }
    }
    return matrix[(int)s1.size()][(int)s2.size()];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
