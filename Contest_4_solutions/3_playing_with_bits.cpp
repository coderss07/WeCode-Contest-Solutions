// Author : Sarthak Sharma
// date: 2021-10-08 21:10:14
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

int main() {
    clock_t begin_69 = clock();
    fast_io;
    ll x, y, n;
    string s;
    cin >> n >> x >> y;
    cin >> s;
    string t = "";
    rep(i, 0, s.size()){
        if (i && s[i] == s[i-1]) continue;
        t += s[i];
    }
    ll Z = 0 ;
    if(t[0] == '0') Z = (t.size() + 1) / 2;
    else Z = t.size() / 2;
    ll ans = Z * y;
    rep(i, 0, Z){
        ans = min(ans, (Z - i) * y + i * x);
    }
    cout << ans << endl;

    return 0;
}