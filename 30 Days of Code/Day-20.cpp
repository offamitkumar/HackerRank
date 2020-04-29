
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
    	cin >> a[a_i];
    }
    int counter{};
    for( int i{}; i < n; ++i ) {
        for( int j{i+1}; j < n; ++j ) {
            if( a[ j ] < a[ i ] ) {
                swap( a[j] , a[i]);
                ++counter;
            }
            
        }
    }

    printf("Array is sorted in %d swaps.\n",counter);
    printf("First Element: %d\n" , a[0]);
    printf("Last Element: %d\n" , a[n-1]);
    return 0;
}
