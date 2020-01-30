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
#define MOD 1000000000
const int MAXC = 1000;
long long c[MAXC + 1][MAXC + 1];
void init() {
    for (int i = 0; i <= MAXC; i++) {
        for (int j = c[i][0] = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
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
    init();
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        int x;
        scanf("%d", &x);
        cout << 1;
        for (int i = 1; i <= x; i++) {
            cout << " " << c[x][i];
        }
        cout << endl;
    }
    return 0;
}
