// Author : Sarthak Sharma
#include<bits/stdc++.h>
// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pii pair<int, int>
#define ff first
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
const int N = 1e5 + 5;
const ll INF = 1e18 + 10;
int a[N], b[N], n, c;

int check(ll x) {
	ll s = 0;
	rep(i, 0, n) {
		double cl = 1 + 1.0 * x * a[i] / b[i];
		if (cl > c + 1)
			return 1;
		s += 1 + x * a[i] / b[i];
		if (s > c)
			return 1;
  	}
	if (s == c) return 0;
	return -1;
}

int main() {
	clock_t begin_69 = clock();
	fast_io;
	cin >> n >> c;
	if(n > c) {
		cout << 0 << endl;;
		return 0;
	}
	bool flag = true;
	rep(i, 0, n) {
		cin >> a[i] >> b[i];
		flag &= (a[i] == 0);
	}
	if(flag) {
		if(n == c) cout << -1 << endl;
		else cout << 0 << endl;
		return 0;
	}
	ll l = 0, r = INF, mid, f;
	while (l < r - 1) {
		mid = (l + r) / 2;
		if (check(mid) >= 0) r = mid;
		else l = mid;
	}
	f = l;
	r = INF;
	while (l < r - 1) {
		mid = (l + r) / 2;
		if (check(mid) == 0) l = mid;
		else r = mid;
	}
	cout << l - f << endl;

	return 0;
}
