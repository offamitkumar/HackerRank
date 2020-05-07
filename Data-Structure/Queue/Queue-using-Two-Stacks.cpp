#include <cmath>
#include <cstdio>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

struct Queue{
    private:
        stack<int>eq; // for enqueue
        stack<int>dq; // for dequeue
    public:
        void push(int x){
            eq.push(x);
        }
        void pop(void){
            if(dq.empty()){
                while(!eq.empty()){
                    dq.push(eq.top());
                    eq.pop();
                }
            }
            dq.pop();
        }
        int front(void){
            if(dq.empty()){
                while(!eq.empty()){
                    dq.push(eq.top());
                    eq.pop();
                }
            }
            return dq.top();
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
