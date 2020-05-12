#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char>stk;
    for(auto&itr:s){
        if(itr=='(' or itr=='[' or itr=='{'){
            stk.push(itr);
        }else{
            if(stk.empty()){
                return "NO";
            }
            if(itr==')' and stk.top() not_eq '('){
                return "NO";
            }
            if(itr==']' and stk.top() not_eq '['){
                return "NO";
            }
            if(itr=='}' and stk.top() not_eq '{'){
                return "NO";
            }
            stk.pop();
        }
    }
    return (stk.size() == 0)?"YES":"NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
