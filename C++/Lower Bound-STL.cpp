#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; cin >> n; 
    vector<int>v(n); 
    for(auto&itr:v)
        cin >> itr;
    cin >> n; 
    while(n--){
        int q; cin >> q; 
        auto itr  = lower_bound(v.begin() , v.end() , q); 
        if(v.at(itr - v.begin()) == q){
            cout <<"Yes "; 
        } else {
            cout <<"No "; 
        }
        cout << (itr - v.begin() +1)  << '\n'; 
    }
    return 0;
}
