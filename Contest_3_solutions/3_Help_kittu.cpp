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
#define _sz(x) (int)x.size()
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)

using namespace std;

// <------------------------------------- Code ------------------------------------->
const int N = 2e5 + 20;
int n , a[N] , l[N] , r[N];
string ans;

int main() {
	clock_t begin_69 = clock();
	fast_io;
	cin >> n;
 
	for(int i = 0; i < n; i++)
		cin >> a[i];
 
	for(int i = 0; i < n; i++) {
		l[i] = 1;
		if (i && a[i] < a[i - 1]) l[i] = l[i - 1] + 1;
	}
 
	for(int i = n - 1; i >= 0; i--) {
		r[i] = 1;
		if(i < n - 1 && a[i] < a[i + 1]) r[i] = r[i + 1] + 1;
	}
 
 
	int p1 = 0, p2 = n - 1, mx = -1;
 
	while (p1 <= p2) {
		if (max(a[p1], a[p2]) <= mx) break;
 
		if(a[p1] < a[p2]) {
			if (a[p1] > mx) {
				mx = a[p1++];
				ans += "L";
			}
			else {
				mx = a[p2--];
				ans += "R";
			}
		}
		else if(a[p1] > a[p2]) {
			if (a[p2] > mx) {
				mx = a[p2--];
				ans += "R";
			}
			else {
				mx = a[p1++];
				ans += "L";
			}
		}
		else {
			if(r[p1] > l[p2]) {
				for(int i = 0; i < r[p1]; i++) ans += "L";	
			}
			else {
				for(int i = 0; i < l[p2]; i++) ans += "R";
			}
			break;
		}
 
	}
 
	cout << _sz(ans) << endl;
	cout << ans << endl;

	return 0;
}
