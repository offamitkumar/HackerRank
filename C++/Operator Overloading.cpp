#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Matrix{
    vector<vector<int>>a; 
    friend Matrix operator+(Matrix&m1 , Matrix&m2) {
        Matrix temp;
        temp.a.resize(m1.a.size()); 
        for(int i=0; i < (int)m1.a.size(); ++i) {
            temp.a.at(i).resize(m1.a[0].size());
            for(int j=0; j<(int)m1.a[0].size();++j){
                temp.a[i][j] = m1.a[i][j] + m2.a[i][j];
            }
        }
        return temp; 
    }
};
int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}
