#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

		/* Enter your code here */
        cout << hex << left << nouppercase; 
        cout << showbase << int64_t(A) << '\n'; 
        cout << fixed << dec << right << setw(15) << setfill('_') << showpos << setprecision(2); 
        cout << B << '\n'; 
        cout << uppercase << noshowbase << scientific << noshowpos << setprecision(9); 
        cout << C << '\n'; 
	}
	return 0;

}
