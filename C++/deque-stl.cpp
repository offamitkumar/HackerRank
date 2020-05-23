#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
    //Write your code here.
    deque<int>d;
    for(int i=0;i<n;++i){
        while((!d.empty()) && arr[d.back()] <= arr[i]) {
            d.pop_back();
        }
        d.push_back(i);
        while((!d.empty()) && i-d.front()>=k){
            d.pop_front();
        }
        if(i>=k-1)
            cout<<arr[d.front()]<<' ';

    }
    cout<<'\n';
}

int main(){
  
    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
              cin >> arr[i];
        printKMax(arr, n, k);
        t--;
      }
      return 0;
}
