#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */     int t;
    cin>>t;
    while(t--){
        long long n; cin >>n;
        if(n==1){
            cout<<"Not prime"<<endl;
            goto hell;
        }
        for(auto i=2;i<=sqrt(n);++i){
            if(n%i==0){
                cout<<"Not prime"<<endl;
                goto hell;
            }
        }
        cout<<"Prime"<<endl;
        hell:
            ;
    }
    return 0;
}
