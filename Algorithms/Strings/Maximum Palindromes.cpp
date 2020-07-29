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
// declarations {{{
vector<int>factorial(MAXN+10);
string s;
vector<vector<int>> stree(4*MAXN , vector<int>(30 , 0));
/*}}}*/
// build{{{
void build(int node , int start , int End){
    if(start == End){
        stree[node][s[start]-'a']++;
        return;
    }
    int mid = (start + End) /2; 
    build(2*node , start , mid); 
    build(2*node+1 , mid+1 , End); 
    for(int i=0; i<30; ++i){
        stree[node][i] = stree[2*node][i] + stree[2*node+1][i];
    }
}
/*}}}*/
// RANGE QUERIES  {{{
vector<int> query(int current_node , int start_, int end_, int q_start, int q_end){
    if(q_start > end_ || q_end < start_ || start_ > end_){
        return vector<int>(30 , 0); // ERROR POINT 2 , CHANGE WITH MIN OR MAX QUERY 
    }
    if(start_ == end_ || (q_start <= start_ && end_ <=q_end)){
        return stree[current_node];
    }
    int mid_point = start_ + (end_ - start_) / 2;
    vector<int> left_ans = query(current_node*2,start_,mid_point,q_start, q_end);
    vector<int> right_ans= query(current_node*2+1,mid_point+1,end_,q_start, q_end);
    for(int i:range(30)){
        (left_ans[i]+=right_ans[i])%=MOD;
    }
    return left_ans;
}
//     }}}
// Mod Inverse/*{{{*/
int64_t inverse(int64_t a, int64_t uMOD = (int64_t)1e9+7ll) { 
    int64_t m0 = uMOD; 
    int64_t y = 0ll, x = 1ll; 
    if (uMOD == 1ll) return 0ll; 
    while (a > 1ll) { 
        int64_t q = a / uMOD; 
        int64_t t = uMOD; 
        uMOD = a % uMOD, a = t; t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0ll) x += m0; 
    return x; 
} 
/*}}}*/

void solve(void){
/* Mod Factoial{{{*/
    factorial[0] = 1;
    for(int i=1;i<=1e5;++i){
        factorial[i] = (factorial[i-1]*i)%MOD;
    }
/*}}}*/
    cin >> s;
    build(1,0,s.size()-1);
// query{{{
    int q; cin >> q; 
    while(q--){
        int l , r; cin >> l >> r; 
        --l , --r; 
        vector<int> v = (query(1 , 0 , s.size()-1 , l , r));
        int counterOdd{} , counterEven{};
        int inv{1};
        for(int i=0; i<30; ++i){
            counterEven += (v[i]/2);
            counterOdd += (v[i]&1);
            inv = (inv  * inverse(factorial[v[i]/2]))%MOD;
        }
        counterEven = (factorial[counterEven]* inv)%MOD; 
        cout << (max(counterOdd, (int)1)*counterEven)%MOD << '\n'; 
   }/*}}}*/
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
