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
#include <numeric>
using namespace std;
#define mod 1000000007

int dig(string s){
    int sum{};
    for(auto &itr:s){
        sum+=(itr-'0');
    }
    return sum;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    long long n; cin>>n;
    long long sum{};
    long long temp = n;
    for(int i=2;i<=sqrt(n)&&temp;++i){
        while(temp%i==0){
            sum+=dig(to_string(i));
            temp/=i;
        }
    }
    if(temp>1){
        sum+=dig(to_string(temp));
    }
    if(sum==dig(to_string(n))){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
    return 0;
}
