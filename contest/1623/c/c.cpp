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
int arr[MAXN], h[MAXN], N;

bool canDo(int x) {
    for (int i = 1; i <= N; i++) h[i] = arr[i];
    for (int i = 1; i <= N; i++) {
        if (h[i] >= x) continue;
        if (i >= N - 1) return false;
        int delta = x - h[i];
        if (delta % 2 == 1) delta ++;
        delta /= 2;
        if (h[i+2] < 3 * delta) return false;
        h[i] += 2 * delta;
        h[i+1] += delta;
        h[i+2] -= delta * 3;
    }
    return true;
}

void solve () {
    cin >> N;
    int tot = 0, L = INF, R = 0;
    for (int i = 1; i <= N; i++) cin >> arr[i], tot += arr[i], L = min(L, arr[i]);
    R = tot / N;
    while (L < R - 1) {
        int M = (L + R) >> 1;
        if (canDo(M)) L = M;
        else R = M - 1;
    }
    if (canDo(R)) cout << R << endl;
    else cout << L << endl;
}

signed main() {
    fast_stream();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}