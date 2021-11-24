/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-11-18 13:46:30
 */
//#pragma GCC optimize("Ofast", "inline", "-ffast-math")
//#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;
void fast_stream() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define int long long
#define COLOR(c) (c == 'B' ? 0 : 1)
const int INF = 0x7fffffffffffffff;
const int MAXN = 2e5 + 9;
int N, arr[MAXN];
vector<int> v[2];
void solve () {
    v[1].clear(), v[0].clear();
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    string color;
    cin >> color;
    for (int i = 0; i < N; i++) {
        v[COLOR(color[i])].push_back(arr[i]);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    for (int i = 0; i < v[0].size(); i++) {
        if (v[0][i] < (i + 1)) { cout << "NO" << endl; return; }
    }
    for (int i = 0; i < v[1].size(); i++) {
        int a = v[1][i], b = N+i-v[1].size()+1;
        if (a > b) { cout << "NO" << endl; return; }
    }
    cout << "YES" << endl;

}

signed main() {
    fast_stream();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}