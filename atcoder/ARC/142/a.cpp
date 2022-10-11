//
// Created by 走线大师 on 2022/6/21.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long

int rev(int N) {
    if (N == 0) return 0;
    int ans = 0;
    while (N > 0) ans = 10 * ans + (N % 10), N /= 10;
    return ans;
}

void solve(int N, int k, int &ans) {
    while (k <= N) ans++, k *= 10;
}

signed main() {
    int N, K;
    cin >> N >> K;
    int rK = rev(K);
    if (rK < K) cout << 0 << endl;
    else {
        int ans = 0;
        solve(N, K, ans);
        if (K != rK) solve(N, rK, ans);
        cout << ans << endl;
    }
}