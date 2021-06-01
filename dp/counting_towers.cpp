#include<bits/stdc++.h>
using namespace std;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr<<endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned ll t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << " {"; _print(p.ff); cerr << ", "; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
/* MODULAR EXPONENTIATION
int modPow(long long x, long long n, int mod){
    if(x==0) return 0;
    if(n==0) return 1;
    long long res = fn(x, n/2, mod);
    res = (res*res)%mod;
    if(n%2){
        res = (res*x)%mod;
    }
    return res;
}
*/
/* SIEVE
vector<int> pr;
void sieve(int n) {
	vector<bool> primes(n + 1, 0);
 
	for (int i = 2; i <= sqrt(n); i++) {
		if (primes[i] == 0) {
			for (int j = i * i; j <= n; j += i) {
				primes[j] = 1;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (primes[i] == 0)
			pr.push_back(i);
	}
}
*/
 
// void solve() {
// 	// int n; cin >> n;
// }
 
ll dp[1000001][2];
int main() {
	fastio();
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	freopen("Error.txt", "w", stderr);
#endif
 
	int t = 1;
	// int t; cin >> t;
	while (t--) {
		int n = 1000000;
		// dp[i][0] -> ways to fill (i)th to (n)th location, if (i - 1)th tiles were not linked(2 tiles of width 1)
		// dp[i][1] -> ways to fill (i)th to (n)th location, if (i - 1)th tiles are linked (1 tile of width 2)
		dp[n + 1][0] = dp[n + 1][1] = 1;
 
		for (int i = n; i >= 2; i--) {
			ll extend_none = (dp[i + 1][0] + dp[i + 1][1]) % MOD;
 
			ll extend_both_linked = dp[i + 1][1];
 
			ll extend_both_unlinked = dp[i + 1][0];
			ll extend_one_unlinked = (2 * dp[i + 1][0]) % MOD;
 
			dp[i][0] = (extend_none + extend_one_unlinked + extend_both_unlinked) % MOD;
 
			dp[i][1] = (extend_both_linked + extend_none) % MOD;
		}
		int q; cin >> q;
		while (q--) {
			int h; cin >> h;
			cout << (dp[1000000 - h + 2][0] + dp[1000000 - h + 2][1]) % MOD << "\n";
		}
	}
	return 0;
}
