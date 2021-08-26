#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int binarySearch(vector<int>&v , vector<int>&t , int len , int s) {
    int start = 0  , finish = len; 
    while (start <= finish) {
        int middle = (finish - start) / 2 + start; 
        if (middle < len && v[t[middle]] < s && v[t[middle+1]] >= s) {
            return middle + 1; 
        } 
        if (v[t[middle]] > s) {
            finish = middle-1; 
        } else {
            start = middle+1; 
        }
    }
    return -1;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n; cin >> n; 
    vector<int>v(n); 
    for(auto&itr:v) cin >> itr; 
    int len = 0; 
    vector<int>t(n+100, 0); 
    for(int i=1; i<n; ++i) {
        if (v[t[0]] > v[i]) { // first value is low , just set it to lis of 1
            t[0] = i; 
        } else if (v[t[len]] < v[i]) { // value is largest we found till , so append it to last 
            t[++len] = i; 
        } else { // need a binary search , value is present in-between 
            int index = binarySearch(v , t, len , v[i]);
            if(index != -1) {
                t[index]=i;
            }
        }
    }
    cout << len+1 << '\n'; 
    return 0;
}
