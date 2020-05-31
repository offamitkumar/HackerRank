#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the sillyGame function below.
 */
const int MAXN = 1e6+100;
bool preC = false;
int arr[MAXN] = {0};

void sieve(void) {
    preC = true;
    bitset<MAXN>isp; isp.set();
    isp.reset(0);
    isp.reset(1);
    for (int i=4; i < MAXN; i+=2) {
        isp.reset(i);
    }
    for(int i=3; i < sqrt(MAXN)+10; ++i) {
        if(isp.test(i)){
            for(long long j=i*i; j<MAXN; j+=i){
                isp.reset(j);
            }
        }
    }
    int counter{};
    for(int i=0; i<MAXN; ++i) {
        counter += (isp[i] == 1);
        arr[i] = counter;
    }
}
string sillyGame(int n) {
    if ( !preC) {
        sieve();
    }
    return (arr[n]&1) ? "Alice" : "Bob"; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = sillyGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
