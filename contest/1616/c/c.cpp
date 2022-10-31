/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2022-01-01 18:22:35
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
const int MAXN = 100;
const double eps = 1e-9;
double ori[MAXN], rep[MAXN];
int N;
void solve () {
    cin >> N;
    int Ans = N;
    for (int i = 1; i <= N; i++) cin >> ori[i];
    if (N == 1) {cout << 0 << endl; return;}
    for (int s = 1; s <= N; s++) {
        for (int e = s + 1; e <= N; e++) {
            double d = (ori[e] - ori[s]) / (e - s);
            rep[e] = ori[e], rep[s] = ori[s];
            for (int i = s - 1; i >= 1; i--) rep[i] = rep[i+1] - d;
            for (int i = s + 1; i <= N; i++) rep[i] = rep[i-1] + d;
            int ans = 0;
            for (int i = 1; i <= N; i++) {
                if (abs(ori[i] - rep[i]) < eps) ans++;
            }
            Ans = min(Ans, N - ans);
        }
    }
    cout << Ans << endl;
}

signed main() {
    fast_stream();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}