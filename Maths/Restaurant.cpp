#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <cassert>
#include <bitset>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;cin>>t;while(t--){
        int l , b; cin>>l>>b;
//        cout<<(l/gcd(l,b))*((b/gcd(l,b)))<<endl;
        cout<<(l*b)/(gcd(l,b)*gcd(l,b))<<endl;
    }
    return 0;
}
