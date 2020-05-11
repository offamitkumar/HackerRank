#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the countSwaps function below.
void countSwaps(vector<int> arr) {
    int swapCounter{};
    for(auto i=0;i<(int)arr.size(); ++i){
        for(auto j=i+1;j<(int)arr.size();++j){
            if(arr[i]>arr[j]){
                swap(arr[j],arr[i]);
                ++swapCounter;
            }
        }
    }
    printf("Array is sorted in %d swaps.\nFirst Element: %d\nLast Element: %d\n",swapCounter , arr[0] , arr[arr.size()-1]);
    return ;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    countSwaps(a);

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
