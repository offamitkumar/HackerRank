#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
#define mod 1000000007

struct Matrix {
    long long arr[2][2];
    Matrix(){
        for(int i=0;i<2;++i){
            for(int j=0;j<2;++j){
                arr[i][j] = 0ll;
            }
        }
    }
};
Matrix operator*(Matrix &A , Matrix &B){
    Matrix T;
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            for(int k=0;k<2;++k){
                T.arr[i][j] += (A.arr[i][k] * B.arr[k][j])%mod;
                T.arr[i][j] =(T.arr[i][j]+mod+mod)%mod;
            }
        }
    }
    return T;
}
Matrix power(Matrix &A , long long n){
    Matrix R;
    R.arr[0][0] = 1;
    R.arr[1][1] = 1;
    while(n){
        if(n&1ll){
            R = R*A;
        }
        A = A*A;
        n>>=1ll;
    }
    return R;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int t;cin>>t;
    while(t--){
        long long a,b,n; cin>>a>>b>>n;
        a%=mod;
        b%=mod;
        if(n==0){
            cout<<a<<endl;
        }else if(n==1){
            cout<<b<<endl;
        }else{
            Matrix A;
            A.arr[0][0]=1ll;
            A.arr[0][1]=1ll;
            A.arr[1][0]=1ll;
            A = power(A , n-1);
/*            for(int i=0; i<2;++i){
                for(int j=0;j<2;++j){
                    cerr<<A.arr[i][j]<<' ';
                }
                cerr<<endl;
            }
 */           cout<<(((b*A.arr[0][0])%mod+mod)%mod+((a*A.arr[0][1])%mod+mod)%mod+mod+mod)%mod<<endl;
        }
    }
    return 0;
}
