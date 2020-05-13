#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    map<char , int>A,B;
    for(auto&itr:a){
        A[itr]++;
    }
    for(auto&itr:b){
        B[itr]++;
    }
    int counter{};
    for(int i=0;i<26;++i){
        counter+=abs(A[i+'a']-B[i+'a']);
    }
    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
