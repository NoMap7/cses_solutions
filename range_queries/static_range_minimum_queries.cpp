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
 

vector<ll> tree(1000000);
ll getmin(int node, int node_low, int node_high, int q_low, int q_high) {
	if (q_low <= node_low && q_high >= node_high) {	//contained
		return tree[node];
	}
	if (node_high < q_low || node_low > q_high) {	//disjoint
		return INT_MAX;
	}
	int mid = node_low + (node_high - node_low) / 2;
	return min(getmin(2 * node, node_low, mid, q_low, q_high), getmin(2 * node + 1, mid + 1, node_high, q_low, q_high));
}
 
void build(int n, vector<int>& ar) {	//iterative
	// build the tree, root is at index 1
	for (int i = 0; i < n; i++) {	//leaf nodes
		tree[n + i] = ar[i];
	}
	for (int i = n - 1; i >= 1; i--) {
		tree[i] = min(tree[2 * i], tree[2 * i + 1]);
	}
}
void build(int node, int node_low, int node_high, vector<int>& ar) {	//recursive
	if (node_low == node_high) {
		tree[node] = ar[node_low];
		return;
	}
	int mid = (node_low + node_high) / 2;
	build(2 * node, node_low, mid, ar);
	build(2 * node + 1, mid + 1, node_high, ar);
	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
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
	// build(n, ar);
	build(1, 0, n - 1, ar);
	//query
	while (q--) {
		int low, high;
		cin >> low >> high;
		low--;
		high--;
		cout << getmin(1, 0, n - 1, low, high) << "\n";
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
