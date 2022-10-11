//
// Created by 走线大师 on 2022/6/27.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int MAXN = 500 * 500 + 10;
int fact[MAXN];
inline int fast_pow(int a, int b) {
    int ans = 1, base = a;
    while (b > 0) {
        if (b % 2 == 1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        b >>= 1;
    }
    return ans;
}
inline int div_mod(int a, int b) {
    return (a * fast_pow(b, mod - 2)) % mod;
}
inline int nCr(int n, int r) {
    return div_mod(fact[n], (fact[r] * fact[n-r]) % mod);
}
signed main() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = (fact[i-1] * i) % mod;
    int n; cin >> n;
    int ans = fact[n*n];
    int q = (n * n * fact[(n-1)*(n-1)]) % mod;
    q = (q * ((fact[n-1]*fact[n-1])%mod)) % mod;
    q = (q * nCr(n*n, 2*n-1)) % mod;
    ans = (ans - q) % mod;
    while(ans < 0) ans += mod;
    cout << ans << endl;
}