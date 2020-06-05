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
#include <unordered_map>
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
    int n; cin>>n;
    map<string , int>phone_book;
    for(int i=0;i<n;++i){
        string s1;int s2;
        cin>>s1;
        if(!(phone_book[s1])){
            cin>>phone_book[s1];
        }
    }
    string que;
    while(cin>>que){
        if((phone_book[que])){
            cout<<que<<'='<<phone_book[que]<<endl;
        }else{
            cout<<"Not found"<<endl;
        }
    }

    return 0;
}
