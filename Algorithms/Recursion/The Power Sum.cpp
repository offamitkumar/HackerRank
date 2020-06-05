#include <bits/stdc++.h>

using namespace std;

// Complete the powerSum function below.
int powerSum(int X, int N , int num = 1) {
    int pw = pow(num,N);
    if(pw< X){
        return powerSum(X , N , num+1) + powerSum(X-pw, N , num+1);
    }else if(pw == X){
        return 1;
    }else{
        return 0;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

    return 0;
}
