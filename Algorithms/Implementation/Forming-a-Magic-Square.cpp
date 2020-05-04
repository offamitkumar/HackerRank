#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <cassert>
#include <bitset>
using namespace std;
bool is_valid(array<int,9>&v){
    int a[3][3]; 
  
    // Convert vector into 3 X 3 matrix 
    for (int i = 0; i < 3; ++i)  
        for (int j = 0; j < 3; ++j)  
            a[i][j] = v[3 * i + j];        
  
    int s = 0; 
    for (int j = 0; j < 3; ++j) 
        s += a[0][j]; 
  
    // Checking if each row sum is same 
    for (int i = 1; i <= 2; ++i) { 
        int tmp = 0; 
        for (int j = 0; j < 3; ++j) 
            tmp += a[i][j]; 
        if (tmp != s) 
            return 0; 
    } 
  
    // Checking if each column sum is same 
    for (int j = 0; j < 3; ++j) { 
        int tmp = 0; 
        for (int i = 0; i < 3; ++i) 
            tmp += a[i][j]; 
        if (tmp != s) 
            return 0; 
    }     
  
    // Checking if diagonal 1 sum is same 
    int tmp = 0; 
    for (int i = 0; i < 3; ++i) 
        tmp += a[i][i]; 
    if (tmp != s) 
        return 0;     
  
    // Checking if diagnol 2 sum is same 
    tmp = 0; 
    for (int i = 0; i < 3; ++i) 
        tmp += a[2 - i][i]; 
    if (tmp != s) 
        return 0; 
    return 1; 
}
int check_sum(array<int,9>&num,array<array<int,3>,3>&arr){
    array<array<int,3>,3>mat;
    int counter = 0;
    int cost = 0;
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            mat[i][j]=num[3*i+j];
            cost+=abs(arr[i][j]-mat[i][j]);
        }
    }
    return cost;
}
int check(array<array<int,3>,3>&arr){
    array<int,9>num;
    int ans = 10000000;
    for(int i=0;i<(int)num.size();++i){
        num[i]=i+1;
    }
    do{
        if(is_valid(num)){
            ans = min(ans , check_sum(num,arr));
        }
    }while(next_permutation(num.begin(),num.end()));
    return ans;
}
int main(void){
    //freopen("input","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    array<array<int,3>,3>arr;
    for(int i=0;i<3;++i){ 
        for(int j=0;j<3;++j){
            cin>>arr[i][j];
        }
    }
    cout<<check(arr)<<endl;
    return 0;
}
