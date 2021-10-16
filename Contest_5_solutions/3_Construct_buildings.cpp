// Author : Sarthak Sharma
// Date: 2021-10-16 15:16:49

// <------------------------------------- Headers Files ------------------------------------->
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pii pair<int, int>
#define ff first
#define mod 1000000007
#define ss second
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab1 " "
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)
#define fbo find_by_order
#define oof order_of_key

using namespace std;
using namespace __gnu_pbds;

// <------------------------------------- Templates ------------------------------------->
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

// <------------------------------------- Code ------------------------------------->

const int N = 1e3 + 13;

int n, m, a[N][N][4], ans[N * N], sum, ms[4] = {1, 2, 3, 0}; //0-left 1-down 2-right 3-up
bool vis[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

bool check(int x, int y) {
	return x >= 1 && y >= 1 && x <= n && y <= m && !vis[x][y];
}

void dfs(int x, int y) {
	vis[x][y] = 1;
	++sum;
	for(int i = 0; i < 4; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if(check(nx, ny)  && !a[x][y][i] && !a[nx][ny][(i + 2) % 4])
			dfs(nx, ny);
	}
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    cin >> n >> m;
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			int x; cin >> x;
			for(int k = 0; k < 4; ++k) a[i][j][ms[k]] = (x & 1), x >>= 1;
		}
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			if(!vis[i][j]) {
				sum = 0;
				dfs(i, j);
				ans[++cnt] = sum;
			}
	sort(ans + 1, ans + cnt + 1, greater<int>());
	for(int i = 1; i <= cnt; ++i) cout << ans[i] << " ";

    #ifndef ONLINE_JUDGE
          clock_t terminator_69 = clock();
          cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    #endif 
    return 0;
}
