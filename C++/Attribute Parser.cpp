#include <bits/stdc++.h>
using namespace std;

int main(void){
//    freopen("input", "r", stdin);
    int n , m; cin >> n >> m; 
    cin.ignore();
    string pref;
    map<string ,string>f;
    for(int i=0; i < n; ++i ) {
        string s; getline(cin ,s);
        istringstream ss(s); 
        ss >> s; 
        if(s[1] == '/'){ // remove last tag
            while(pref.size() && pref.back() != '.'){
                pref.pop_back();
            }
            if(pref.size())
                pref.pop_back();
            continue;
        }else{ // time to add a new tag
            if(pref.size()){
                if(s.back()=='>'){
                    s.pop_back();
                }
                s[0] = '.';
                pref+=s;
            }else{
                if(s.back()=='>'){
                    s.pop_back();
                }
                pref+=s.substr(1 , s.size()-1);
            }
        }
        while(ss >> s){
            string key , value;
            if(s[0] != '"' || s[0]!='='){
                if(s.back()=='>'){
                    s.pop_back();
                }
                key = pref+"~"+s;
            }else{break;}
            ss >> s; 
            ss >> s; 
            for(int i=1; i<s.size()-1;++i){
                if(s[i]=='"')break;
                value+=s[i];
            }
            f[key] = value;
        }
    }
    while(m--){
        cin >> pref;
        auto itr = f.find(pref);
        if(itr!=f.end()){
            cout << itr->second << '\n'; 
        }else{
            cout << "Not Found!" << '\n'; 
        }
    }
    return 0;
}
