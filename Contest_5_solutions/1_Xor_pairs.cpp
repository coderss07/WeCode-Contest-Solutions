// Author : Sarthak Sharma
// Date: 2021-10-08 21:10:14
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


void solve() {
    int n, x, y, tmp, val, count;
    map<int, int> amap, bmap;
    cin >> n >> x >> y;
    count = 0;
    rep(i, 0, n) {
        cin >> tmp;
        val = (tmp & x) ^ (tmp & y);
        amap[val]++;
    }
    rep(i, 0, n) {
        cin >> tmp;
        val = (tmp & x) ^ (tmp & y);
        bmap[val]++;
    }
    map<int,int>::iterator it;
    for(auto j = amap.begin(); j != amap.end(); j++) {
        it = bmap.find((*j).ff);
        if(it != bmap.end()){
            count = count + ((*j).ss) * ((*it).ss);
        }
    }
    cout << count << endl;
}

int main() {
    clock_t begin_69 = clock();
    fast_io;
    int t; cin >> t;
    while(t--) {
        solve();
    }

    #ifndef ONLINE_JUDGE
        clock_t terminator_69 = clock();
        cerr << "\nExecuted In: " << double(terminator_69 - begin_69) / CLOCKS_PER_SEC * 1000 << " ms" << endl;
    #endif
    return 0;
}
