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
const int N = 1005;
int n, m1, m2, f[N], ff[N], x, y, o, vis[N], last[N], nex[N], viss[N];
pii z[N];

int find(int x) {
	if(f[x] == 0) return x;
	return f[x] = find(f[x]);
}

int ffind(int x) {
	if(ff[x] == 0) return x;
	return ff[x] = ffind(ff[x]);
}

void erase(int i) {
	nex[last[i]] = nex[i];
	last[nex[i]] = last[i];
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    cin >> n >> m1 >> m2;
	nex[0] = 1;
	rep(i, 1, n + 1) {
		last[i]=i-1;
		nex[i]=i+1;
	}
	rep(i, 0, m1) {
		cin >> x >> y;
		f[find(x)] = find(y);
	}
	rep(i, 0, m2) {
		cin >> x >> y;
		ff[ffind(x)] = ffind(y);
	}
	rep(i, 1, n + 1) {
		if(ffind(i) != i) {
			erase(i);
			viss[i] = 1;
		}
			
	}
	rep(i, 1, n + 1) {
		if(vis[find(i)]) continue;
		vis[find(i)] = 1;
		for(int j = nex[0]; j != n + 1; j = nex[j])
		if(find(i) != find(j) && ffind(i) != ffind(j)) {
			z[++o] = make_pair(i, j);
			if(!viss[ffind(j)])
			erase(ffind(j)), viss[ffind(j)] = 1;
			f[find(j)] = find(i);
			ff[ffind(j)] = ffind(i);
			
		}
	
	}
	cout << o << endl;
	rep(i, 1, o + 1) {
		cout << z[i].ff << " " << z[i].ss << endl;
	}

    return 0;
}