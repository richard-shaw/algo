//
// Created by 走线大师 on 2021/9/15.
//

#include <bits/stdc++.h>

using namespace std;
#define MOD 998244353
#define int long long

int G(int n) {
    int Ans = 0;
    for (int i = 1; i <= n;) {
        int j = n / (n / i);
        Ans = (Ans + ((n / i) * (j - i + 1)) % MOD) % MOD;
        i = j + 1;
    }
    return Ans;
}

signed main() {
    int l, r, Ans;
    cin >> l >> r;
    if (l > r) Ans = 0;
    else Ans = G(r) - G(l-1);
    while(Ans < 0) Ans += MOD;
    cout << Ans << endl;
}