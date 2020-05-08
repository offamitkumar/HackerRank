#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n; cin>>n;
    int m; cin>>m;
    for(int i=n;i<=m;++i){
        switch(i){
            case 1:
                cout<<"one";
                break;
            case 2:
                cout<<"two";
                break;           
            case 3:
                cout<<"three";
                break;    
            case 4:
                cout<<"four";
                break; 
            case 5: 
                cout<<"five";
                break; 
            case 6:
                cout<<"six";
                break; 
            case 7:
                cout<<"seven";
                break; 
            case 8:
                cout<<"eight";
                break; 
            case 9:
                cout<<"nine";
                break;
            default:
                if(i&1){
                    cout<<"odd";
                }else{
                    cout<<"even";
                }
        }
        cout<<endl;
    }
    return 0;
}
