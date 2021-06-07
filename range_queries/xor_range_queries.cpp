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
/* GCD
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
*/

vector<int> tree(1000000);
// vector<ll> lazytree(1000000);
// vector<ll> tree;


int getxor(int node, int node_low, int node_high, int q_low, int q_high) {
	if (q_low <= node_low && q_high >= node_high) {
		return tree[node];
	}
	if (q_low > node_high || q_high < node_low) {
		return 0;
	}
	int mid = (node_low + node_high) / 2;
	return (getxor(2 * node, node_low, mid, q_low, q_high) ^ getxor(2 * node + 1, mid + 1, node_high, q_low, q_high));
}

void build(int node, int node_low, int node_high, vector<int>& ar) {	//recursive
	if (node_low == node_high) {
		tree[node] = ar[node_low];
		return;
	}
	int mid = (node_low + node_high) / 2;
	build(2 * node, node_low, mid, ar);
	build(2 * node + 1, mid + 1, node_high, ar);

	tree[node] = tree[2 * node] ^ tree[2 * node + 1];
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> ar(n);
	for (int &x : ar) {
		cin >> x;
	}

	// while (__builtin_popcount(n) != 1) {
	// 	n++;
	// }
	// tree.resize(2 * n);

	//build segment tree
	build(1, 0, n - 1, ar);
	//query
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << getxor(1, 0, n - 1, a, b) << "\n";
	}
}

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
		solve();
	}
	return 0;
}
