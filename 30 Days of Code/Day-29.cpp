#include <bits/stdc++.h>
using namespace std;
int main(void){
    int t; cin>>t;
    while(t--){
        int a, b;cin>>a>>b;
        if(b&1){
            cout<<b-1<<endl;
        }else{
            if(((b-1)|b)<=a){
                cout<<b-1<<endl;
            }else{
                cout<<b-2<<endl;
            }
        }
    }
    return 0;
}
