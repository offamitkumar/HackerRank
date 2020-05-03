#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n , q;
    cin>>n>>q;
    vector<vector<int>>arr(n);
    for(int i=0;i<n;++i){
        int e;
        cin>>e;
        for(int k,j=0;j<e;++j){
            cin>>k;
            arr[i].push_back(k);
        }
    }
    while(q--){
        int i ,j;
        cin>>i>>j;
        cout<<arr[i][j]<<'\n';
    }
    return 0;
}
