#include <bits/stdc++.h>

using namespace std;
// Complete the abbreviation function below.
unordered_set<string>dp;
bool ans_found;
void rec(string A, string B) {
    if (ans_found || A.size() < B.size()) {
        return ;
    }
    if(B.empty()) {
       if(all_of(A.begin(), A.end(), [](char ch){ return islower(ch); }))
           ans_found = true;
        return;
    }
    auto p = dp.insert(A + '$' + B);
    if(!p.second){
        return ;
    }
    auto ch = A[0];
    A.erase(0, 1);
    if (islower(ch)) rec(A, B);
    if (toupper(ch) != B[0]) return; 
    B.erase(0, 1);
    rec(A, B);
    return ;
}
string abbreviation(string a, string b) {
    dp.clear();
    ans_found = false;
    rec(a, b);
    return ans_found ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
