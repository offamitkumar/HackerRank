#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <cassert>
#include <bitset>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n; cin>>n;
    vector<int>leader_board(n);
    for(auto &itr:leader_board){
        cin>>itr;
    }
    vector<int>ranks(n);
    ranks[0] = 1;
    for(int i=1;i<n;++i){
        if(leader_board[i]==leader_board[i-1]){
            ranks[i] = ranks[i-1];
            continue;
        }
        ranks[i]=ranks[i-1]+1;
    }
    ranks.push_back(ranks[n-1]+1);
    int alice;cin>>alice;
    int curr_rank = ranks[ranks.size()-1];
    int ci = n-1;
    for(int i=0;i<alice;++i){
        int score; cin>>score;
        while(ci>=0 && score>leader_board[ci]){
            ci--;
        }
        if(score==leader_board[ci]){
            cout<<ranks[ci]<<endl;
            continue;
        }else if(score<leader_board[ci]){
            cout<<ranks[ci]+1<<endl;
        }else{
            cout<<1<<endl;
        }
    }
    return 0;
}
