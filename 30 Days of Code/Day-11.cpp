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



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int arr[6][6];
    for(int i=0;i<6;++i){
        for(int j=0;j<6;++j){
            cin>>arr[i][j];
        }
    }
    int max_sum{INT_MIN};
    for(int i=0;i<=3;++i){
        for(int j=0;j<=3;++j){
            max_sum = max(max_sum , arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2]);
        }
    }
    cout<<max_sum<<endl;
    return 0;
}
