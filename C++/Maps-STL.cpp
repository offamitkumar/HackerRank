#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q; cin >> q; 
    map<string , int>f;
    while(q--){
        int a,b; string c; 
        cin >> a >> c; 
        switch(a){
            case 1:
                cin >> b;
                f[c]+=b;
                break;
            case 2:
                f[c]=0;
                break;
            case 3:
                cout << f[c] << '\n';
                break;
        }
    }
    return 0;
}
