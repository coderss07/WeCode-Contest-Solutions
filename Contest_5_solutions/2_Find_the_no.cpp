// Author : Sarthak Sharma
// Date: 2021-10-14 16:50:41

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
#define ss second
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define tab1 " "
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, b, a) for(int i = b - 1; i >= a; i--)

using namespace std;
using namespace __gnu_pbds;

// <------------------------------------- Templates ------------------------------------->
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

// <------------------------------------- Code ------------------------------------->

const int N = 1e5;
const int mod = 1e9 + 7;

int solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    if(a > b) swap(a, b);
    ll l = a, r = n * a;
    ll lcm = a * b/ __gcd(a, b);
    while(l <= r) {
        ll mid = (l + r) / 2;
        ll ind = (mid / a) + (mid / b) - (mid / lcm);
        if(ind == n && (mid % a == 0 || mid % b == 0)) return mid % mod;
        if(ind < n) l = mid + 1;
        else r = mid - 1;
    }
        
    return -1;
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    int t; cin >> t;
    while(t--) {
        cout << solve() << endl;
    }

    #ifndef ONLINE_JUDGE
        clock_t terminator_69 = clock();
        cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    #endif
    return 0;
}