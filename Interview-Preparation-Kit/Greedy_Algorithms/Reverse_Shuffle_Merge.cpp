#include <bits/stdc++.h>

using namespace std;

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s) {
    map<char,int>s1Counter , s2Counter; 
    for(auto&itr:s){
        s1Counter[itr]++;
        s2Counter[itr] = s1Counter[itr]/2;
    }
    string ans="";
    reverse(s.begin() , s.end());
    for(auto&itr:s){
        if(s2Counter[itr]>0){
            while(not(ans.empty())){
                if(ans.back() > itr){
                    if(s1Counter[ans.back()]>=s2Counter[ans.back()]+1){
                        s2Counter[ans.back()]++;
                        ans.pop_back();
                    }else{
                        break;
                    }
                }else{
                    break;
                }
            }
            ans.push_back(itr);
            s2Counter[itr]--;
        }
        s1Counter[itr]--;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
