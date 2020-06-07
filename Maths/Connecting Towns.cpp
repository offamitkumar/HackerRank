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
const long long prime = 1234567ll;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;n--;
        long long ans = 1ll;
        while(n--){
            int x; cin>>x;
            ans = (ans * x)%prime;
        }
        cout<<ans<<endl;
    }
    return 0;
}
