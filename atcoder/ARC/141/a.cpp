//
// Created by 走线大师 on 2022/6/29.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long

int pw[20];
int peri(int k, int l, int n) {
    int ans = 0;
    while (n--) ans = pw[l] * ans + k;
    return ans;
}
int solve(int N, int l, int L) {
    int k = 0;
    string sN = to_string(N);
    for (int i = 0; i < l; i++) k = 10 * k + sN[i] - '0';
    int sK = peri(k, l, L / l);
    return sK <= N ? sK : peri(k-1, l, L / l);
}

signed main() {
    pw[0] = 1;
    for (int i = 1; i < 20; i++) pw[i] = 10 * pw[i-1];
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int L = to_string(N).length();
        int ans = peri(9, 1, L-1);
        for (int i = 1; i <= L / 2; i++) {
            if (L % i != 0) continue;
            ans = max(ans, solve(N, i, L));
        }
        cout << ans << endl;
    }
}