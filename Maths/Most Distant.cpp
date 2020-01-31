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
#include <iomanip>
#include <numeric>
using namespace std;
#define mod 1000000007



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
    long long max_x{-10000} , max_y{-1000000} , min_y{100000000} , min_x{10000000};
    while(n--){
        long long x,y;cin>>x>>y;
        max_y = max(max_y , y);
        max_x = max(max_x , x);
        min_y = min(min_y , y);
        min_x = min(min_x , x);
    }
    double current = max(max_x-min_x , max_y - min_y);

    current = max(current,(double)sqrt(max_x*max_x+max_y*max_y));
    current = max(current,(double)sqrt(min_x*min_y+max_y*max_y));
    current = max(current,(double)sqrt(max_x*max_x+min_y*min_y));
    current = max(current,(double)sqrt(min_x*min_x+min_y*min_y));
    cout<<fixed<<setprecision(6)<<current<<endl;
    return 0;
}
