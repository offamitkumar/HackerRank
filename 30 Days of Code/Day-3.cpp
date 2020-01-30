
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if(N&1){
        cout<<"Weird"<<endl;
    }else{
        if(N<=5 and N>=2){
            cout<<"Not Weird"<<endl;
        }else if(N>=6 and N<=20){
            cout<<"Weird"<<endl;
        }else{
            cout<<"Not Weird"<<endl;
        }
    }
    return 0;
}
