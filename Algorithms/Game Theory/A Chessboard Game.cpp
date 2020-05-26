#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the chessboardGame function below.
string chessboardGame(int x, int y) {
    if (x%4==0 || x%4==3 || y%4==0 || y%4==3){
        return "First";
    }else{
        return "Second";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string xy_temp;
        getline(cin, xy_temp);

        vector<string> xy = split_string(xy_temp);

        int x = stoi(xy[0]);

        int y = stoi(xy[1]);

        string result = chessboardGame(x, y);

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
