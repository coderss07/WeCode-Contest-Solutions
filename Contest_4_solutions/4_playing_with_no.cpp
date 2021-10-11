// Author : Sarthak Sharma
// Date: 2021-10-11 21:39:17
#include<bits/stdc++.h>
// <------------------------------------- Directives ------------------------------------->
#define ll long long int
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pii pair<int, int>
#define ff first
#define N 1e5
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

using namespace std;

// <------------------------------------- Code ------------------------------------->

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers
ll lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
void solve() {
    ll k, l; cin >> k >> l;
    unordered_map<ll, ll> count;
    count[k]++;
    while(1) {
        ll num = lcm(k,l);
        ll val = num/l;
        k = val;
        if(val == 1) {
            cout << "YES" << endl;
            break;  
        }  
        if(count[val] > 0) {
            cout << "NO" << endl;
            break;   
        }
        count[val]++;
    }
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}