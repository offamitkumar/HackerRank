#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    int candyValue = 1;
    if(n==1){
        return 1;
    }
    vector<int>l_to_r(n,1) , r_to_l(n,1);
    for(int i=1;i<n;++i){
        if(arr[i]>arr[i-1]){
            l_to_r[i] = l_to_r[i-1]+1;
        }else{
            l_to_r[i] = 1;
        }
    }
    long counter{};
    for(int i=n-2;i>=0;--i){
        if(arr[i]>arr[i+1]){
            r_to_l[i] = r_to_l[i]+r_to_l[i+1];
        }
    }
    for(int i=0;i<n;++i){
       counter+=max(r_to_l[i] , l_to_r[i]); 
    }
    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
