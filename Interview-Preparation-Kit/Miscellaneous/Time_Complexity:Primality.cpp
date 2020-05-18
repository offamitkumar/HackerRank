#include <bits/stdc++.h>

using namespace std;

// Complete the primality function below.
string primality(int n) {
    for(auto i=2;i<=sqrt(n);++i)
        if(n%i==0)
            return "Not prime";
    return (n==1)?"Not prime":"Prime";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int p_itr = 0; p_itr < p; p_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = primality(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
