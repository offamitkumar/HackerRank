#include <bits/stdc++.h>

using namespace std;
bool ispow(long long n){
    return (n && (!((n-1 )& n)));
}

// Complete the counterGame function below.
string counterGame(long n) {
    short player = 1;
    while(n != 1) {
        assert(n>=1);
        player = player^1;
        if(ispow(n)){
            n/=2;
        }else{
            long long pw = (1LL<<61);
            while(pw > n){
                pw>>=1;
            }
            n-=pw;
        }
    }
    return player ? "Richard" : "Louise"; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
