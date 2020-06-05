#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n; cin>>n;
    stack<int>s;
    while(n--){
        int x;cin>>x;
        s.push(x);
    }
    while(s.size()){
        cout<<s.top()<<' ';
        s.pop();
    }
    return 0;
}
