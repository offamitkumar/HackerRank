#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
    if(is_sorted(arr.begin() , arr.end())){
        cout <<"yes";
        return;
    }
    int i = 0 , j = (int)arr.size()-1;
    for(int k = 0; k+1<(int)arr.size();++k){
        if(arr[k]>arr[k+1]){
            i = k;
            break;
        }
    }
    for(int k=arr.size()-1;k>0;--k){
        if(arr[k]<arr[k-1]){
            j=k;
            break;
        }
    }
    swap(arr[i] , arr[j]);
    if(is_sorted(arr.begin() , arr.end())){
        cout << "yes" << '\n' << "swap "<< 
            i+1 << ' ' << j+1 << '\n'; 
        return;
    }else{
        swap(arr[i] , arr[j]);
    }

    reverse(arr.begin()+i , arr.begin()+j+1);
    
    if(is_sorted(arr.begin() , arr.end())){
        cout << "yes" << '\n' << "reverse "<< 
            i+1 << ' ' << j+1 << '\n'; 
        return;
    }else{
        cout << "no" << '\n'; 
        return;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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
