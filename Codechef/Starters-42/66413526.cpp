#include <bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;

/*------ TypeDef Micro's -------*/
using ll = long long;
using li = long int;
using ld = long double;
using lli = long long int;
using vb = std::vector<bool>;
using vvb = std::vector<vb>;
using vi = std::vector<int>;
using vvi = std::vector<vi>;

using mii = std::map<int, int>;
using mll = std::map<long long, long long>;
using mci = std::map<char, int>;
using msi = std::map<string, int>;
using umii = std::unordered_map<int, int>;
using umll = std::unordered_map<long long, long long>;
using si = std::set<int>;
using sll = std::set<long long>;
using sc = std::set<char>;
using ss = std::set<string>;


/*--------- Loop's Shortcuts ------------*/
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, b) for (int i = (0); i < (b); ++i)
#define REP(i, a, b) for (int i = int(a); i >= b; --i)
#define R0P(i, b) for (int i = int(b); i >= 0; --i)
#define each(i, arr) for (auto &i : arr)

/*-------- In-Built Func^ Shortcuts ------*/

#define pb push_back
#define ppb pop_back
#define pf  push_front
#define ppf pop_front
#define mp(p1,p2) make_pair(p1,p2);
#define eb emplace_back
#define Fi first
#define Si second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sum(x) accumulate(all(x), 0LL)
#define init(arr,val) memset(arr,val,sizeof(arr))
#ifndef ONLINE_JUDGE
#define deb(...) cout << "[" << #__VA_ARGS__ << "] = ", print(__VA_ARGS__)
#else
#define deb(...)
#endif
#define sz(x) ((long long)(x).size())
#define make_unique(x) sort(all(x)); auto it = unique(all(x)); x.resize(it - x.begin())
#define endl "\n"
#define lb lower_bound // lower bound -> Lower Bound of X = first element >= X in the DS
#define ub upper_bound // Upper bound -> Upper Bound of X = first element > X in the DS

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.exceptions(ios::badbit | ios::failbit);
template <typename T, typename U> std::ostream &operator<<(std::ostream &stream, const pair<T, U> &p){
    return stream << p.first << " " << p.second;}
template <typename T1, typename U> std::istream &operator>>(istream &is, pair<T1, U> &p){
    is >> p.first >> p.second;return is;}
template <typename T> std::ostream &operator<<(std::ostream &out, const vector<T> &vec){
    for (const T &x : vec) out << x << ' '; return out;}
template <typename T> std::istream &operator>>(istream &in, vector<T> &v){
    for (auto &i : v)in >> i;return in;}
template <typename T> void print(T &&t) { cout << t << '\n'; }
template <typename T, typename... Args>void print(T &&t, Args &&...args){cout << t << " ";
    print(forward<Args>(args)...);}
template <class T>void print(set<T> Set){for (T i : Set){cout << i << " ";}}
template <class T, class V>void print(map<T, V> Map){for (T i : Map){cout << i << " ";}}
template <class T>void print(multiset<T> MutliSet){for (T i : MutliSet){cout << i << " ";}}
template <class T>void print(vector<T> Vector){for (T i : Vector){cout << i << " ";}}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r){ return uniform_int_distribution<int>(l, r)(rng); }

/*--------  Pre-difined Constants-------*/
constexpr long long mod = 1e9 + 7 , inf = 1e18; 
constexpr int Mod_N = 10e5 + 5; constexpr ld Eps = 1e-9;
const double PI = 3.141592653589793238462; // 2 * asin(1.0);

/*--------- Predefined Function  ---- */
vector<pair<long long, long long>> primeFactor(long long n){vector<pair<long long, long long>>pfact; 
  for(ll i=2; i*i<=n; ++i) if(n%i==0){ll cnt=0; while(n%i==0) {++cnt; n/=i;} pfact.pb({i,cnt});}
  if(n>1) pfact.pb({n,1});  return pfact;
}
constexpr int setbit(int x) { return __builtin_popcount(x); } // # of bits set
constexpr long long setbit(long long x) { return __builtin_popcountll(x);}
constexpr int zerobits(int x){return __builtin_ctz(x);} // # zero bits occuring before first set bit
constexpr long long zerbits (long long x) { return __builtin_ctz(x);}
template <typename T>T roundUp(T a, T b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
template <typename T>T roundDown(T a, T b) { return a / b - ((a ^ b) < 0 && a % b); } // divide a by b rounded down
template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0;} // TO check Min
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0;} // TO check Max
long long binpow(long long a, long long b) { a %= mod;long long res = 1;while (b > 0) {
    if (b & 1){res = res * a % mod;} a = a * a % mod;b >>= 1;}return res;}//Binary Exponentiation( calculate A ^ B ) O(log b)
// Sieve of Erastosthenes---> O(n* log(logn))
vector<long long> sieve(int n) {int *arr = new int[n + 1](); vector<long long>sieveVect; 
    for (int i = 2; i <= n; ++i)if (arr[i] == 0) {sieveVect.push_back(i); 
    for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return sieveVect;}
bool isPrime(long long n){if(n==1){return false;} for(ll i=2; i*i<=n; ++i){ 
    if(n%i==0) return false;} return true;} // Prime or not-----O(sqrt(n))
bool perfectsq (long long n){ if(ceil(double(sqrt(n)) == floor(double(sqrt(n)))))return true; 
    else return false;}  //Perfect square or not----->O(1)
auto Dcmp = [](auto a, auto b){ // Descending Lambda comparator 
    return a >= b;
};
auto Acmp = [](auto a, auto b) { // Accending Lambda Comparator 
    return a <= b;
};
struct Hash {  // http://xorshift.di.unimi.it/splitmix64.c
    const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    static uint64_t splitmix64(uint64_t bit) {
        bit += 0x9e3779b97f4a7c15;
        bit = (bit ^ (bit >> 30)) * 0xbf58476d1ce4e5b9;
        bit = (bit ^ (bit >> 27)) * 0x94d049bb133111eb;
        return bit ^ (bit >> 31);
    }
    size_t operator()(uint64_t x) const {
        return splitmix64(x + FIXED_RANDOM);
    }
};
const int N = 2005;
const int maxN = 2e5 + 5;

void solveit(){
        int X,Y; 
        cin>>X>>Y; 
        int count = 0; 
        int cntX = X%3; 
        int cntY =  Y%3; 
        if( cntX == 0 || cntY == 0){ 
            print(0); 
        } 
        else if(cntX==cntY){ 
            print(1); 
        } 
        else{              
          print(2); 
        } 
}

int main(int argc, char const *argv[]){
    fast;

    int ase = 1;
    cin >> ase;

    while (ase--){
        solveit();
    }

    return 0;
}
