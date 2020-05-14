#include <bits/stdc++.h>

using namespace std;
int freq[(int)1e6+10];
// Complete the substrCount function below.
long substrCount(int n, string s) {
    long result{}; 
    memset(freq , 0 , sizeof(freq));
    for(int i = 0; i<n; ++i){
        long counter{};
        int j = i;
        while(j<n and s[i] == s[j]){
            ++j , ++counter;
        }
        for(int k = i;k<=j-1;++k){
            freq[k] = counter;
        }
        i = j-1;
        result+=(counter*(counter+1ll))/2ll;
    }
    for(int i=1;i<n-1;++i){
        if(freq[i]==1 and s[i-1] == s[i+1])
            result+=min(freq[i-1] , freq[i+1]);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
