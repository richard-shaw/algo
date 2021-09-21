/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-09-04 16:46:12
 */

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
int arr[MAXN], N, L, R;

inline int get_less_or_equal(int x, int i) {
    return upper_bound(arr + i, arr + N, x) - arr - i;
}

inline int get_less(int x, int i) {
    return lower_bound(arr + i, arr + N, x) - arr - i;
}

void solve () {
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    int Ans = 0;
    for (int i = 0; i < N - 1; i++) {
        int l = L - arr[i], r = R - arr[i];
        Ans += (get_less_or_equal(r, i+1) - get_less(l, i+1));
    }
    cout << Ans << endl;
}

signed main() {
    fast_stream();
    int t;
    cin >> t;
//t = 1;
    while (t--) {
        solve();
    }
}