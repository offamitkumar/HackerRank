#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a,b;cin>>a>>b;
    cout<<a.size()<<' '<<b.size()<<endl<<a+b<<endl;
    swap(b[0],a[0]);
    cout<<a<<' '<<b<<endl;
    return 0;
}
