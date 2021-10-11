// Author : Sarthak Sharma
#include<bits/stdc++.h>
// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pii pair<int, int>
#define ff first
#define N 1e6
#define mod 1000000007
#define ss second
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab " "
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)

using namespace std;

// <------------------------------------- Code ------------------------------------->
vi price;
vi val;
vvi dp;

int vitamin(int n, int value) {
	if(value == 7) {
		return 0;
	}
	if(n <= 0) {
		return N;
	}
	if(dp[n][value] == -1) {
		dp[n][value] = min(vitamin(n - 1, value), vitamin(n - 1, (value | val[n - 1])) + price[n - 1]);
	}
	return dp[n][value];
}

void solve() {
	int n; cin >> n;
	price = vi(n);
	val = vi(n);
	dp = vvi(n + 1, vi(8, -1));
	rep(i, 0, n) {
		cin >> price[i];
		string s; cin >> s;
		int tmp = 0;
		rep(j, 0, s.size()) {
			tmp = (tmp | (1 << ('C' - s[j])));
		}
		val[i] = tmp;
	}
	int ans = vitamin(n, 0);
	if(ans >= N) {
		cout << -1 << endl;
		return;
	}
	cout << vitamin(n, 0) << endl;

}

int main() {
	clock_t begin_69 = clock();
	fast_io;
	solve();

	return 0;
}