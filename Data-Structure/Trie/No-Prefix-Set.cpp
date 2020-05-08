#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
using namespace __gnu_pbds;
typedef tree< // find_by_order & order_of_key
        int ,
        null_type ,
        less<int> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
struct Node{
    Node * arr[30] = {nullptr};
    bool isEnd = false;
};
Node *root; 
bool found(const string &s){ // return false if any prefix found 
    Node*temp = root;
    for(int i=0;i<(int)s.size();++i){
        int it = s[i]-'a';
        if(root->arr[it]==nullptr){
            root -> arr[it] = new Node();
            root = root->arr[it];
            if(i+1==s.size()){
                root->isEnd = true; // mark current node as end of a word
            }
        }else{
            if(root->arr[it]->isEnd == true){
                return true;
            }
            root = root->arr[it];
            if(i+1==s.size()){
                root->isEnd = true; // mark current node as end of a word
                return true; // current word end here and another prefix is already there 
            }
        }
    }
    root->isEnd = true; // mark current node as end of a word
    root=temp;
    return false;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n; cin>>n;
    root = new Node();
    while(n--){
        string s; cin>>s;
        if(found(s)){
            puts("BAD SET");
            cout<<s;
            goto hell;
        }
    }
    puts("GOOD SET");
hell:
    ;
    return 0;
}
