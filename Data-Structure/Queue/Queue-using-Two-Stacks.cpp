#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Queue{
    private:
        vector<int>v;
    public:
        void push(int x){
            v.push_back(x);
        }
        void pop(void){
            v.erase(v.begin());
        }
        int front(void){
            return *v.begin();
        }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */     int Q; cin>>Q;
    Queue q;
    while(Q--){
        int type;
        cin>>type;
        switch(type){
            case 1:
                int x; cin>>x;
                q.push(x);
            break;
            case 2:
                q.pop();
            break;
            case 3:
                cout<<q.front()<<endl;
            break;
        }
    }
    return 0;
}
