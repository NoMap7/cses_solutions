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

int fn(int a, int b, vector<vector<int>> &memo) {
	if (a == b) {
		return 0;
	}
	if (memo[a][b] != -1) return memo[a][b];

	int t = INT_MAX;
	for (int i = 1; i <= b / 2; i++) {  //try cutting  vertically
		t = min(t, (fn(a, i, memo) + fn(a, b - i, memo)));
	}
	
	int v = INT_MAX;
	for (int i = 1; i <= a / 2; i++) {   //try cutting horizontally
		v = min(v, (fn(i, b, memo) + fn(a - i, b, memo)));
	}
	
	return memo[a][b] = 1 + min(t, v);
}
void solve() {
	int a, b;
	cin >> a >> b;
	vector<vector<int>> memo(a + 1, vector<int>(b + 1, -1));
	int ans = fn(a, b, memo);
	cout << ans << "\n";
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
