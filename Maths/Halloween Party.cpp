#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the halloweenParty function below.
 */
long halloweenParty(long long k) {
    /*
     * Write your code here.
     */
    if(k&1){
        return (k/2ll)*(k/2ll+1ll);
    }else{
        return (k/2ll)*(k/2ll);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int k;
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = halloweenParty(k);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
