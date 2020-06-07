#include <bits/stdc++.h>
using namespace std;
int X[] = {-2,-2,1,-1};
int Y[] = {1,-1,-2,-2};
int arr[33][33]; 
int check(int x , int y){
    if(x<=0 || y<=0 || x>15 || y>15){
        return 0; // invalid point  grundy number will be 0 
    }
    return 1; // valid point 
}
int grundy(int a , int b){
    if(a == 1 && b == 1){
        return 0;
    }
    if(arr[a][b]!=-1){
        return arr[a][b];
    }
    set<int>found;
    for(int i = 0; i<4;++i){
        int tempX = a + X[i];
        int tempY = b + Y[i];
        if(tempX>=1 and tempY>=1 && tempX<=15 && tempY<=15){
            found.insert(grundy(tempX,tempY));
        }
    }
    int counter = 0;
    while(found.find(counter)!=found.end()){ // searching MEX
        ++counter;
    }
    return arr[a][b] = counter;
}
int main(void){
    memset(arr,-1,sizeof(arr));
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = 0 , x,y;
        for(int i=1;i<=n;++i){
            cin >> x >> y; 
            ans ^= grundy(x,y);
        }
        if(ans){
            cout <<"First"<<'\n';
        }else{
            cout <<"Second"<<'\n';
        }
    }
    return 0;
}
