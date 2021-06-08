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

/* idea is to create a difference array for the given input array, so the 
original array will act as a prefix sum array for the difference array, 
create a range sum segment tree for the diff array, 
to get index k, in the input array, just return range sum[0, k],
to update[a, b, val] , add val to index[a] and -val to index[b+1], such that
the range sum is maintained
*/

	
vector<ll> tree(1000000);

ll getsum(int node, int node_low, int node_high, int q_low, int q_high) {
	if (q_low <= node_low && q_high >= node_high) {
		return tree[node];
	}

	if (q_low > node_high || q_high < node_low) {
		return 0;
	}

	int mid = node_low + (node_high - node_low) / 2;
	return (getsum(2 * node, node_low, mid, q_low, q_high) + getsum(2 * node + 1, mid + 1, node_high, q_low, q_high));
}

void update(int node, int node_low, int node_high, int q_low, int q_high, int val) {	//recursive

	if (q_low <= node_low && q_high >= node_high) {	//leaf
		tree[node] += val;
		return;
	}
	if (node_high < q_low || node_low > q_high) {	//disjoint
		return;
	}
	int mid = node_low + (node_high - node_low) / 2;
	update(2 * node, node_low, mid, q_low, q_high, val);
	update(2 * node + 1, mid + 1, node_high, q_low, q_high, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void build(int node, int node_low, int node_high, vector<ll>& ar) {	//recursive
	if (node_low == node_high) {
		tree[node] = ar[node_low];
		return;
	}
	int mid = node_low + (node_high - node_low) / 2;
	build(2 * node, node_low, mid, ar);
	build(2 * node + 1, mid + 1, node_high, ar);

	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void solve() {
	ll n, q;
	cin >> n >> q;
	vector<ll> ar(n);
	for (ll &x : ar) {
		cin >> x;
	}
	vector<ll> a;
	a.pb(ar[0]);
	for (int i = 1; i < n; i++) {
		a.pb(ar[i] - ar[i - 1]);
	}
	a.shrink_to_fit();
	

	//build segment tree
	build(1, 0, n - 1, a);

	// query
	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			ll low, high, val;
			cin >> low >> high >> val;
			low--;
			update(1, 0, n - 1, low, low, val);
			// if (high <= n - 1)
			update(1, 0, n - 1, high, high, -val);
			// debug(tree);
		} else {
			ll k;
			cin >> k;
			k--;
			cout << getsum(1, 0, n - 1, 0, k) << "\n";
		}
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
