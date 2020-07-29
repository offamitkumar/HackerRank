// {{{ 
// Header Files {{{

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <numeric>
#include <utility>

#include <bitset>
#include <tuple>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <deque>

#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdio>

using namespace std;
using namespace std::chrono;

using namespace __gnu_pbds;

template<typename TypeInfo>
using new_set = tree< // find_by_order & order_of_key
TypeInfo ,
         null_type ,
         less<TypeInfo> ,
         rb_tree_tag ,
         tree_order_statistics_node_update 
         > ;

/* }}} */ 
/*Debug Section{{{*/

void Log_Gen() { cerr << endl; }
template <typename HEAD, typename... TAIL>
void Log_Gen(HEAD H, TAIL... T) {
  cerr << " " << (H);
  Log_Gen(T...);
}
#ifdef HELL_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", Log_Gen(__VA_ARGS__)
#else
#define debug(...) 0
#endif

/* }}} */
// defines & constants /*{{{*/

#define int int64_t
const int MAXM = (int)1e5+100;
const int MAXN = (int)1e5+100;
const int MOD = (int)1e9+7;

/*}}}*/
// range & VPi /*{{{*/

template<typename A, typename B>
ostream& operator<<(ostream&out, const pair<A, B>&p){
    out << p.first << ' ' << p.second ;
    return out;
}

template<typename A, typename B>
istream& operator>>(istream&in, pair<A, B>&p){
    in >> p.first >> p.second ;
    return in;
}

template<typename A> 
istream& operator>>(istream&in, vector<A>&vec){
    for(auto&itr:vec){
        in >> itr;
    }
    return in;
}

template<typename A>
ostream& operator<<(ostream&out,const vector<A>&vec){
    for(auto&itr:vec){
        out << itr <<' '; // VVV 
    }
    return out;
}

class NumberIterator : iterator<forward_iterator_tag, int> {
    public:
        int v;

        NumberIterator(int x) : v(x) {}

        operator int &() { return v; }

        int operator*() { return v; }
};
class range : pair<int,int> {
    public:
        range(int begin, int end) : pair<int,int>(begin, max(begin, end)) {}
        range(int n) : pair<int,int>((int)0, max((int)0, n)) {}

        NumberIterator begin() {
            return first;
        }

        NumberIterator end() {
            return second;
        }
};

/*}}}*/
// /*}}}*/
void solve(void){
/*Input & Declarations {{{*/
    int n , k; cin >> n >> k; 
    string s; cin >> s; 
    bitset<100010>changed; changed.reset();
    int i = 0 , j = n-1; 
/*}}}*/
/*Check if palindrome or we can make it palindrome{{{*/
    while(i<j){
        if(s[i] != s[j]){
            if(s[i] > s[j]){
                s[j] = s[i];
                changed[j] = true;
            }else{
                s[i] = s[j];
                changed[i] = true;
            }
            --k;
        }
        if(k<0){
            cout <<-1<<'\n';
            return;
        }
        ++i; 
        --j;
    }
/*}}}*/
/*If moves remains{{{*/
    if(k != 0){
        i = 0 , j = n-1;
        while(i<=j && k){
            if(s[i]!='9'){
                if(changed[i] || changed[j] || i == j){
                    s[i] = '9';
                    s[j] = '9';
                    k-=1;
                }else if(k>=2){
                    s[i] = '9';
                    s[j] = '9';
                    k-=2;
                }
            }
            ++i; 
            --j;
        }
    }
/*}}}*/
    cout << s << '\n'; 
}
// Main Function {{{

signed main(void){

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 

    ios::sync_with_stdio(false); // FLUSH THE STREAM IF USING puts / printf / scanf/
    cin.tie(nullptr);            // DISABLE FOR INTERACTIVE PROBLEMS
    cout.tie(nullptr);           //

#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 

    solve();

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}

/*}}}*/
