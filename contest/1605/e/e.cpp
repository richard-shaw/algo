/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-11-24 15:41:41
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
int N, Q, A[MAXN], B[MAXN], SUM_0[MAXN], SUM_2[MAXN];
pair<int, int> C[MAXN];
vector<int> V[3];
int less_count(int id, int v) {
    return lower_bound(V[id].begin(), V[id].end(), v) - V[id].begin();
}
signed main() {
    fast_stream();
    V[0].clear(), V[1].clear(), V[2].clear();
    memset(SUM_0, 0, sizeof(SUM_0));
    memset(SUM_2, 0, sizeof(SUM_2));
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];

    C[1].first = 0, C[1].second = 1;
    for (int i = 2; i <= N; i++) {
        C[i].first = B[i] - A[i];
        C[i].second = -1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                C[i].first -= C[j].first;
                C[i].second -= C[j].second;
                if (j * j != i) {
                    C[i].first -= C[i / j].first;
                    C[i].second -= C[i / j].second;
                }
            }
        }
        V[C[i].second+1].push_back(C[i].first);
    }
    sort(V[0].begin(), V[0].end());
    sort(V[2].begin(), V[2].end());
    for (int i = 0; i < V[0].size(); i++) SUM_0[i+1] = SUM_0[i] + V[0][i];
    for (int i = 0; i < V[2].size(); i++) SUM_2[i+1] = SUM_2[i] + V[2][i];
    int N0 = V[0].size(), N2 = V[2].size();
    int ans0 = 0;
    for (int a : V[1]) ans0 += abs(a);
    cin >> Q;
    while (Q--) {
        cin >> B[1];
        int x = B[1] - A[1];
        int less_x_0 = less_count(0, x), less_x_2 = less_count(2, -x);
        int Ans = ans0;
        Ans += abs((SUM_0[N0] - 2 * SUM_0[less_x_0] + x * (2 * less_x_0 - N0)));
        Ans += abs((SUM_2[N2] - 2 * SUM_2[less_x_2] + x * (N2 - 2 * less_x_2)));
        Ans += abs(x);
        cout << Ans << endl;
    }
}