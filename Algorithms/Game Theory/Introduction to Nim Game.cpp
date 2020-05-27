#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the nimGame function below.
string nimGame(vector<int> pile) {
    int winner = 0;
    for(auto&itr:pile){
        winner^=itr;
    }
    return (winner)?"First":"Second";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string pile_temp_temp;
        getline(cin, pile_temp_temp);

        vector<string> pile_temp = split_string(pile_temp_temp);

        vector<int> pile(n);

        for (int i = 0; i < n; i++) {
            int pile_item = stoi(pile_temp[i]);

            pile[i] = pile_item;
        }

        string result = nimGame(pile);

        fout << result << "\n";
    }

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
