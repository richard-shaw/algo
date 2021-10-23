/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-10-17 19:05:03
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
const int MAXN = 100 + 9;
int arr[MAXN];
bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
vector<int> s;
void solve () {
    int N, sum = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i], sum += arr[i];
    if (sum % 2 == 0) {
        cout << N << endl;
        for (int i = 1; i < N; i++) cout << i << ' ';
        cout << N << endl;
    } else {
        if (!is_prime(sum)) {
            cout << N << endl;
            for (int i = 1; i < N; i++) cout << i << ' ';
            cout << N << endl;
        } else {
            cout << N - 1 << endl;
            int i;
            for (i = 1; i <= N; i++) {
                if (arr[i] % 2 == 1) break;
            }
            s.clear();
            for (int j = 1; j <= N; j++) {
                if (i != j) s.push_back(j);
            }
            for (int q = 0; q < s.size(); q++) {
                cout << s[q];
                if (q == s.size() - 1) cout << endl;
                else cout << ' ';
            }
        }
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