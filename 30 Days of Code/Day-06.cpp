#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n; cin>>n;
    while(n--){
        string s;
        cin>>s;
        string e{""},o{""};
        for(int i=0;i<(int)s.size();++i){
            if((i+1)&1){
                o.push_back(s[i]);
            }else{
                e.push_back(s[i]);
            }
        }
        cout<<o<<' '<<e<<endl;;
    }
    return 0;
}
