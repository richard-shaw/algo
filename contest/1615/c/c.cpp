/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-12-27 15:50:59
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
int Ans;
set<string> visit;
void dfs(int a, int b, int c, int d, int ans) {
    string key = to_string(a) + "|" + to_string(b) + "|" + to_string(c) + "|" + to_string(d);
    if (visit.find(key) != visit.end()) return;
    if (b == 0 && c == 0) {
        Ans = min(Ans, ans);
        return;
    }
    visit.insert(key);
    if (ans > Ans) return;
    if (c > 0) dfs(c-1, d, a+1, b, ans+1);
    if (d > 0) dfs(c, d-1, a, b+1, ans+1);
}
void solve () {
    visit.clear();
    int N, status[4] = {0, 0, 0, 0};
    string A, B;
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) status[(A[i]-'0')*2+B[i]-'0']++;
    Ans = INF;
    dfs(status[0], status[1], status[2], status[3], 0);
    cout << (Ans == INF ? -1 : Ans) << endl;
}

signed main() {
    fast_stream();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}