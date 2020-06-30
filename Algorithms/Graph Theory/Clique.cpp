//  Author : Amit Kumar 

#include <iostream>
#include <algorithm> 
#include <string> 
#include <sstream>
#include <fstream>
#include <iomanip> 
#include <chrono> 
#include <numeric> 
#include <utility>
#include <functional>

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
#include <list>


#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdio>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define all(x)  (x).begin(), (x).end()

using namespace std;
using namespace std::chrono;
//  using namespace placeholders;
using namespace __gnu_pbds;
template<typename TypeInfo>
using new_set = tree< 
/* ob.order_of_key(element) -> number of element strictly less than element
 * *ob.find_by_order(n) ->  nth element in increasing order
 */
         TypeInfo ,
         null_type ,
         less<TypeInfo> ,
         rb_tree_tag ,
         tree_order_statistics_node_update 
 > ;

void Log_Gen() { cerr << endl; }
 
template <typename HEAD, typename... TAIL>
void Log_Gen(HEAD H, TAIL... T) {
  cerr << " " << (H);
  show_me(T...);
}
 
#ifdef HELL_JUDGE
#define Log(...) cerr << "[" << #__VA_ARGS__ << "]:", Log_Gen(__VA_ARGS__)
#else
#define Log(...) 0
#endif

typedef int64_t Int;

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
        range(int n) : pair<int,int>(0, max(0, n)) {}
        NumberIterator begin() {
            return first;
        }
        NumberIterator end() {
            return second;
        }
};

template<typename Container , typename ValType>
bool present(const Container &t , const ValType &val){
    return (t.find(val) != t.end());
}

template<>
bool present<string>(const string &s , const char &val){
    return (s.find(val) == string::npos);
}

template<>
bool present<string>(const string &s , const string &val){
    return (s.find(val) == string::npos);
}
 
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

const int MAXM = (int)1e5+100;
const int MAXN = (int)1e5+100;
const int64_t MOD  = (int64_t)1e9+7ll;

// copied from wiki, if someone knows what kind of shit is this
// please mail me : offamitkumar@gmail.com 
int turan(int n, int k) {
    return (n*n - (n%k)*(n%k ? n/k+1 : n/k)*(n%k ? n/k+1 : n/k) - (k - n%k)*(n/k)*(n/k)) / 2;
}

int search(int n, int m) {
    int low=2, up=n;
    while(up-low > 1) {
        int midturan = turan(n, (low+up) / 2);
        if(midturan > m) up = (low+up) / 2;
        else if(midturan < m) low = (low+up) / 2;
        else    return (low+up)/2;
    }
    if(turan(n, low) >= m)  return low;
    else if(turan(n, up) < m ) return up+1;
    return up;
}



signed main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    ios::sync_with_stdio(false); // FLUSH THE STREAM IF USING puts / printf / scanf/
    cin.tie(nullptr);            //
    cout.tie(nullptr);           //
#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 

    int t; cin >> t; 
    while(t--){
        double n,m; cin>>n>>m;
        cout << search(n,m) << '\n'; 
    }

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}
