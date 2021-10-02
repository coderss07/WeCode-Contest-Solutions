// Author : Sarthak Sharma
#include<bits/stdc++.h>
// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pii pair<int, int>
#define ff first
#define N 1e5
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

void solve() {
    ll n; cin >> n;
    ll ans = 1, y = n - 1, x = 2;
    while(y > 0) {
        if(y % 2 != 0) {
            ans = ((ans % mod) * (x % mod)) % mod;
        }
        x = ((x % mod) + (x % mod)) % mod;
        y /= 2;
    }
    cout << ans << endl;
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}