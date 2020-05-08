
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */     int n ; cin>>n;
    vector<int>v(n);
    for(auto&itr:v){
        cin>>itr;
    }
    for(auto itr = v.rbegin(); itr!=v.rend(); ++itr){
        cout<<*itr<<' ';
    }
    cout<<endl;
    return 0;
}
