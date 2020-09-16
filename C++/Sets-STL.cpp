#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q; cin >> q; 
    set<int>s;
    while(q--){
        int a , b; cin >> a >> b; 
        switch(a){
            case 1:
                s.insert(b);
                break;
            case 2:
                s.erase(b);
                break;
            case 3:
                puts((s.find(b)!=s.end())?"Yes":"No");
                break;
        }
    }
    return 0;
}
