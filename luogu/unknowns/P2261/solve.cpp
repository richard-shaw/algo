/** 数论分块 */
#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int n, k;
    cin >> n >> k;
    int Ans = n * k, i = 1;
    while(i <= min(n, k)) {
        int t = k / i, j = min(n, k / t);
        Ans -= t * (i + j) * (j - i + 1) / 2;
        i = j + 1;
    }
    cout << Ans << endl;
}