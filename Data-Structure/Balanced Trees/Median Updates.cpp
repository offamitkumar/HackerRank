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

    int64_t N;
    cin >> N;

    vector<char> s;
    vector<int64_t> X;
    char temp;
    int64_t tempint;
    for(int64_t i = 0; i < N; i++){
        cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
    }

    int64_t n=s.size();
    multiset<int64_t> m,m1;
    for(int64_t i=0;i<n;i++){
        if(s[i]=='a'){
            if(m.size()==0 || (*m.rbegin())>=X[i]){
                m.insert(X[i]);
                if(m.size()-m1.size()==2){
                    int64_t x=*m.rbegin();
                    m.erase(m.find(x));
                    m1.insert(x);
                }   
            }
            else {
                m1.insert(X[i]);
                if(m1.size()>m.size()){
                    int64_t x=*m1.begin();
                    m1.erase(m1.find(x));
                    m.insert(x);
                }
            }   
        }
        else{
            if(m.find(X[i])==m.end() && m1.find(X[i])==m1.end()){
                cout<<"Wrong!\n";
                continue;
            }
            else if(m.find(X[i])!=m.end()){
                m.erase(m.find(X[i]));
                if(m.size()<m1.size()){
                    int64_t x=*m1.begin();
                    m1.erase(m1.find(x));
                    m.insert(x);
                } 
            }
            else {
                m1.erase(m1.find(X[i]));
                if(m.size()-m1.size() >=2){
                    int64_t x=*m.rbegin();
                    m.erase(m.find(x));
                    m1.insert(x);
                }
            }
        }
        if(m.size()==0 && m1.size()==0) {
            cout<<"Wrong!\n";
            continue;
        }
        if(m1.size()==0){
            cout<<*m.rbegin()<<endl;
            continue;
        }
        double db=((m.size()>m1.size() ? *m.rbegin(): (*m.rbegin()+*m1.begin())/2.0));
        if(ceil(db)!=db) cout<<fixed<<setprecision(1)<<db<<endl;
        else  cout<<fixed<<setprecision(0)<<db<<endl;
    }

    return 0;
}
