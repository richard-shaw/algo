/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2022-01-02 21:31:22
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
pair<int, int> pr[1003];
int N, ans[1003];
void dfs(int idx) {
    if (pr[idx].first == pr[idx].second) { ans[idx] = pr[idx].first; return; }
    int find[2] = { -1, -1 };
    for (int i = 1; i <= N; i++) {
        if (pr[i].first == pr[idx].first && pr[i].second < pr[idx].second) {
            if (find[0] != -1 && pr[find[0]].second > pr[i].second) {
                continue;
            }
            find[0] = i;
        }
        if (pr[i].second == pr[idx].second && pr[i].first > pr[idx].first) {
            if (find[1] != -1 && pr[find[1]].first < pr[i].first) {
                continue;
            }
            find[1] = i;
        }
    }
    if (find[0] != -1) {
        ans[idx] = pr[find[0]].second + 1;
        dfs(find[0]);
    }
    if (find[1] != -1) {
        ans[idx] = pr[find[1]].first - 1;
        dfs(find[1]);
    }
}
void solve () {
    cin >> N;
    int st = -1;
    for (int i = 1; i <= N; i++) {
        cin >> pr[i].first >> pr[i].second;
        ans[i] = -1;
        if (pr[i].first == 1 && pr[i].second == N) st = i;
    }
    dfs(st);
    for (int i = 1; i <= N; i++) {
        cout << pr[i].first << ' ' << pr[i].second << ' ' << ans[i] << endl;
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