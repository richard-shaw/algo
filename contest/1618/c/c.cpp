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
int arr[103], N;
void solve () {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    bool ok = true;
    int d = arr[1];
    for (int i = 1; i <= N; i+= 2) {
        d = __gcd(d, arr[i]);
    }
    for (int i = 2; i <= N; i+= 2) {
        if (arr[i] % d == 0) { ok = false; break; }
    }
    if (ok) {
        cout << d << endl;
        return;
    }

    ok = true;
    d = arr[2];
    for (int i = 2; i <= N; i+= 2) {
        d = __gcd(d, arr[i]);
    }
    for (int i = 1; i <= N; i+= 2) {
        if (arr[i] % d == 0) { ok = false; break; }
    }
    if (ok) {
        cout << d << endl;
    } else {
        cout << 0 << endl;
    }

}

signed main() {
    fast_stream();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}