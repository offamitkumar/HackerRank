#include <bits/stdc++.h>
using namespace std;
#define int int64_t

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n; cin >> n; 
    map<int, vector<pair<int,string>>>f;  // stable sorted ;) 

    map<tuple<int,int,string>, int>st; // stores the element {index , number{input} , string{input}} which
    // will be replaced by dash. Index is taken so that we can figure out which number to replace.

    for(int i=1;i<=n;++i){
        int x; string y; cin >> x >> y; 
        if(i<=n/2){
            st[make_tuple(i,x,y)]++;
        }
        f[x].push_back(make_pair(i , y));
    }

    for(auto&itr:f){
        int t= (int)itr.second.size(); 
        for(int i = 0; i < t; ++i){
            auto j = st.find(make_tuple(itr.second[i].first,itr.first , itr.second[i].second));
            if(j!=st.end()){
                cout<<"- ";
                st.erase(j);
            }else{
                cout << itr.second[i].second<<' ';
            }
        }
    }
    cout << '\n'; 
    return 0;
}
