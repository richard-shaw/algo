/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-12-16 17:46:48
 */
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;
void fast_stream() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define int long long
const int INF = 0x7fffffffffffffff;
const int MAXN = 2e5 + 9;
string S[104];
void solve () {
    int N;
    cin >> N;
    for (int i = 1; i < N-1; i++) cin >> S[i];
    int idx = N-1;
    for (int i = 2; i < N - 1; i++) {
        if (S[i][0] != S[i-1][1]) {
            idx = i;
            break;
        }
    }
    cout << S[1];
    for (int i = 2; i < N-1; i++) {
        if (i == idx) cout << S[i];
        else cout << S[i][1];
    }
    if (idx == N - 1) {
        cout << 'a';
    }
    cout << endl;
}

signed main() {
    fast_stream();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}