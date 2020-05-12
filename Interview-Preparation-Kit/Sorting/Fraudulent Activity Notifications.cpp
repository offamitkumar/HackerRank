#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
array<int ,204>freq;
double get_mid(int d){
    int sum = 0;
    int i=0;
    for(i=0;i<201;++i){
        sum += freq[i];
        if(sum>=d)
            return i;
    }
    return i;
}

// Complete the activityNotifications function below.
int activityNotifications(vector<int> &expenditure, int d) {
    int ans = 0;
    int n = (int)expenditure.size();
    int temp_start = 0;
    for(int i=0;i<n;++i){
        if(i>=d){
            int mid = get_mid(d%2+d/2);
            if(not(d&1)){
                if(expenditure[i] >= mid + get_mid(d/2+1)){
                    ++ans;
                }
            }else{
                if(expenditure[i]>=2*mid){
                    ++ans;
                }
            }

            --freq[expenditure[temp_start++]];
        }
        ++freq[expenditure[i]];
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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
