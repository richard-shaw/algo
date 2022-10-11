//
// Created by Shaw on 2022/10/2.
//

/**
 * 求较大n，m的组合数，适用条件模数p较小且为素数的情况
 */
typedef long long LL;
const int maxn = 1e6 + 9;


LL fact[maxn];
void init_fact(LL mod) {
    fact[0] = fact[1] = 1ll % mod;
    for (int i = 2; i < maxn; i++) fact[i] = (fact[i-1] * i) % mod;
}
LL fast_pow(LL a, LL b, LL p) {
    LL ans = 1, base = a;
    while (b > 0) {
        if (b & 1) ans = (ans * base) % p;
        base = (base * base) % p;
        b >>= 1;
    }
    return ans;
}

LL inv(LL a, LL b, LL p) {
    b = fast_pow(b, p - 2, p);
    return (a * b) % p;
}
LL C(LL n, LL m, LL p) {
    if (m == n || m == 0) return 1ll;
    if (n < m) return 0ll;
    return (((fact[n] * inv(1ll, fact[m], p)) % p) * inv(1ll, fact[n-m], p)) % p;
}

LL lucas(LL n, LL m, LL p) {
    if (n < p && m < p) return C(n, m, p);
    return (lucas(n / p, m / p, p) * C(n % p, m % p, p)) % p;
}