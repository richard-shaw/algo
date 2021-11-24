/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-10-29 16:24:46
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
int cnt[30], n, visit[MAXN];

void solve () {
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < 30; j++) {
            cnt[j] += (a & 1);
            a >>= 1;
        }
        visit[i] = 0;
    }
    int ck = 0;
    for (int k = 1; k <= n; k++) {
        bool ok = true;
        for (int j = 29; j >= 0; j--) {
            if (cnt[j] % k != 0) {ok = false; break;}
        }
        if (ok) {
            visit[k] = 1;
            ck++;
        }
    }
    int cck = 0;
    for (int k = 1; k <= n; k++) {
        if (!visit[k]) continue;
        cout << k;
        if ((++cck) == ck) cout << endl;
        else cout << ' ';
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