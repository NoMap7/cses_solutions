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

/*  APPROACH FOR THE SOLUTION
dp[i][j] -> score of p1 in array[i....j] assuming p1 chooses first

		p1 chooses optimally -> for the array [i.....j]

		if p1 chooses i -> p2 chooses optimally -> in [i+1,....j]
		if p1 chooses j -> p2 chooses optimally -> in [i....j-1]
*/

void solve() {
	int n; cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	vector<vector<ll>> dp(n, vector<ll>(n));
	for (int g = 0; g < n; g++) {
		for (int i = 0, j = g; j < n; i++, j++) {
			if (g == 0) {
				dp[i][j] = ar[i];
			} else if (g == 1) {
				dp[i][j] = max(ar[i], ar[j]);
			} else {
				ll lmax = ar[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
				ll rmax = ar[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
				dp[i][j] = max(lmax, rmax);
			}
		}
	}
	cout << dp[0][n - 1] << "\n";
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
