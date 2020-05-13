#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    array<int,26>arr; fill (arr.begin() , arr.end() , 0);
    set<char>st;
    for(auto&itr:s){
        arr[itr-'a']++;
        st.insert(itr);
    }
    bool erased=false;
    for(int i=0;i<26;++i){
        if(!arr[i]) continue;
        int wc=0;
        for(int j=0;j<26;++j){
            if(!arr[j] || i == j)continue;
            if(arr[i]!=arr[j]){
                if(erased){
                    return "NO";
                }
                if(abs(arr[i]-arr[j])!=1 && arr[i]>1 && arr[j]>1 ){
                    return "NO";
                }else{
                    erased = true;
                    if(arr[i] == 1){
                        arr[i] = 0;
                    }else{
                        arr[j] = 0;
                    }
                    break;
                }
            }
        }
        if(wc && wc != 1 && wc+1 != st.size()){
            return "NO";
        }
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
