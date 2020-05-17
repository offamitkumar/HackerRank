#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> contests) {
    long long total_luck{} , lost_luck;
    vector<int>imp , not_imp;
    for(auto&itr:contests){
        if(itr[1]){
            imp.emplace_back(itr[0]);
        }else{
            not_imp.emplace_back(itr[0]);
        }
    }
    const size_t must_win = max((int)imp.size()-k,0);
    sort(imp.begin() , imp.end() );
    lost_luck = accumulate(imp.begin() , imp.begin()+must_win , 0ll);
    total_luck = accumulate(imp.begin()+must_win , imp.end(),0ll);
    total_luck += accumulate(not_imp.begin() , not_imp.end(),0ll);
    if(k>imp.size()){
        return total_luck+lost_luck;
    }
    return total_luck - lost_luck;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    //freopen("input","r",stdin);
    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> contests(n);
    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> contests[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = luckBalance(k, contests);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
