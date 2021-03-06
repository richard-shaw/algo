/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-10-02 18:33:42
 */
//#pragma GCC optimize("Ofast", "inline", "-ffast-math")
//#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
//
using namespace std;

void fast_stream() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
//#define int long long
const int INF = 2e9+21;
const int MAXN = 404;
int sum[MAXN][MAXN], n, m, PRO[MAXN][MAXN];
char buf[MAXN];
struct ANS {
    int start, value;
} dp[MAXN];

void init() {
    for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= m + 1; j++) sum[i][j] = 0;
}
int count1(int i, int j, int s, int t) { return sum[s][t] + sum[i-1][j-1] - sum[i-1][t] - sum[s][j-1]; }
int count0(int i, int j, int s, int t) { return PRO[s - i + 1][t - j + 1] - count1(i, j, s, t); }
int get_ans(int i, int j, int s, int t) {
    return count1(i+1, j+1, s-1, t-1) + count0(i, j+1, i, t-1) + count0(s, j+1, s, t-1) + count0(i+1, j, s-1, j) + count0(i+1, t, s-1, t);
}
void solve () {
//    cin >> n >> m;
    scanf("%d%d", &n, &m);
    init();
    int result = INF;
    for (int i = 1; i <= n; i++) {
//        string s;
//        cin >> s;
        scanf("%s", buf);
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i][j - 1] + (buf[j - 1] - '0');
        }
        for (int j = 1; j <= m; j++) {
            sum[i][j] += sum[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (k <= 3 || (j - i) <= 3) { dp[k].value = INF; continue; }
                if (k == 4) {
                    dp[k].start = 1;
                    dp[k].value = get_ans(i, 1, j, k);
                } else {
                    dp[k].start = dp[k - 1].start, dp[k].value = dp[k - 1].value +
                                                                 count1(i + 1, k - 1, j - 1, k - 1) +
                                                                 count0(i, k - 1, i, k - 1) +
                                                                 count0(j, k - 1, j, k - 1) +
                                                                 count0(i + 1, k, j - 1, k) -
                                                                 count0(i + 1, k - 1, j - 1, k - 1);
                    int ans1 = get_ans(i, k - 3, j, k);
                    if (ans1 < dp[k].value) {
                        dp[k].value = ans1;
                        dp[k].start = k - 3;
                    }
                }
                result = min(result, dp[k].value);
            }
        }
    }
    cout << result << endl;
}

signed main() {
//    fast_stream();
    int t;
//    cin >> t;
    scanf("%d", &t);
    for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) PRO[i][j] = i * j;
    while (t--) {
        solve();
    }
}