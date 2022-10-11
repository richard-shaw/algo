/* Generated by powerful Codeforces Tool
 * Author: shaw
 * Time: 2022-03-08 22:35:01
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
const int INF = 0x7fffffffffffffff;
const int MAXN = 2e5 + 9;

int getMAX(int a, int k, int il, int ir) {
    if (ir <= a - 1 - k) return ir;
    if (il >= a - k) return ir;
    else return a - 1;

}

void solve () {
    int l, r, a;
    cin >> l >> r >> a;
    if (a == 1) { cout << r << endl; return; }
    int kl = l / a, kr = r / a;
    if (kl == kr) {
        cout << (r / a) + (r % a) << endl;
    } else {
        int Ans = max(a - 1 + kr - 1, (r / a) + (r % a));
        cout << Ans << endl;
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