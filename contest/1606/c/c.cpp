/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-10-29 22:35:04
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
int pow10[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
void solve () {
    int n, k, a[10];
    vector<int> v;
    v.clear();

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < n - 1; j++) {
        int k0 = pow10[a[j + 1] - a[j]] - 1;
        if (k0 < k) v.push_back(k0), k -= k0;
        else {v.push_back(k); k = 0; break;}
    }
    if (k > 0) v.push_back(k);
    while (v.size() < n) v.push_back(0);
//    for (int i = n-1; i >= 1; i--) {
//        int j = n - i - 1;
//        if (v[i] < pow10[a[j+1]-a[j]] - 1) {v[i]++; break;}
//    }
    bool ok = false;
    for (int i = 0; i < n-1; i++) {
        if (v[i] < pow10[a[i+1]-a[i]]-1) {v[i]++; ok = true;break;}
    }
    if (!ok) {
        v[v.size()-1]++;
    }
    for (int i = v.size()-1;i>=0;i--) if (v[i] > 0) cout << v[i];
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