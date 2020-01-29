#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b && n>=a)
using namespace std;
typedef long long LL;
#define MOD 1000000007
#define MAX 1000033
LL mpow(LL a, LL n)
{
    LL ret=1;
    LL b=a;
    while(n)
    {
        if(n&1)ret=(ret*b)%MOD;
        b=(b*b)%MOD;
        n>>=1;
    }
    return (LL)ret;
}
LL fac[MAX],inv[MAX];
void precalc()
{
    LL i;
    fac[0]=1;
    inv[0]=1;
    fac[1]=1;
    inv[1]=1;
    for(i=2; i<MAX; i++)
    {
        fac[i]=(i*fac[i-1])%MOD;
        inv[i]=mpow(fac[i],MOD-2);
    }
}
LL choose(LL n,LL r)
{
    if(n<r)return 0ll;
    LL ret1=(inv[r]*inv[n-r])%MOD;
    LL ret=(ret1*fac[n])%MOD;
    return ret;
}
int main()
{
    precalc();
    int t;
    cin >> t;
    assn(t,1,200);
    while(t--)
    {
        LL n,m,t=1ll,ans=1ll;
        cin >> m >> n;
        assn(n,1,1000);
        assn(m,1,1000);
        n--;
        m+=n;
        cout << choose(m,n) << endl;
    }
    return 0;
}
