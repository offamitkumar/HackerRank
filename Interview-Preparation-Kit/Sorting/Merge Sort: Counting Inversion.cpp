#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long ans;
array<int,100089>temp;
void merge(vector<int>&arr , int start , int end){
    int mid = (start + end)/2;
    int i = start , j = mid+1 , k = start;
    while(i<=mid and j<=end){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }else{
            ans+=(mid - (i-1));
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=end){
        temp[k++] = arr[j++];
    }
    for(k = start; k<=end;++k){
        arr[k] = temp[k];
    }
}
void mergeSort(vector<int>&arr  , int start , int end){
    if(start >= end){
        return;
    }
    int mid = (start + end)/2;
    mergeSort(arr , start , mid);
    mergeSort(arr , mid+1 , end);
    merge(arr , start , end);
}

// Complete the countInversions function below.
long countInversions(vector<int>&arr) {
   ans = 0;
   mergeSort(arr , 0 , arr.size()-1);
   return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        long result = countInversions(arr);

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
