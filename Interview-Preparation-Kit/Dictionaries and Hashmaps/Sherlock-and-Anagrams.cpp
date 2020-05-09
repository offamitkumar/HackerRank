#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {

    map<vector<int> , int>f;
    for(auto i=0;i<s.size();++i){
        vector<int>v(30);
        for(auto j=i;j<s.size();++j){
            v[s[j]-'a']++;
            f[v]++;
        }
    }
    int counter{};
    for(auto&itr:f){
        counter+=((itr.second)*(itr.second-1))/2;
    }
    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
