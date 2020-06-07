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

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        set<int>s;
        for(int i=1;i*i<=n;++i){
            if(n%i==0){
                s.insert(i);
                s.insert(n/i);
            }
        }
        int counter{};
        for(auto&itr:s){
            counter+=(!(itr&1));
        }
        cout<<counter<<endl;
    }
    return 0;
}
