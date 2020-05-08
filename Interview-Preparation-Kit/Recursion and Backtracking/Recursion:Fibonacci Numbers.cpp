#include <iostream>

using namespace std;

int fibonacci(int n) {
    // Complete the function.
    return (n<=1)?n:fibonacci(n-1)+fibonacci(n-2);
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}
