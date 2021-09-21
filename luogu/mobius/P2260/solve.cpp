//
// Created by 走线大师 on 2021/9/14.
//

#include <bits/stdc++.h>

using namespace std;
#define MOD 19940417
#define int long long
int add(int count, ...) {
    int Ans = 0;
    va_list va;
    va_start(va, count);
    while(count--) Ans = (Ans + va_arg(va, long long)) % MOD;
    va_end(va);
    while(Ans < 0) Ans += MOD;
    return Ans;
}
int mul(int count, ...) {
    int Ans = 1;
    va_list va;
    va_start(va, count);
    while (count--) {
        int q = va_arg(va, long long);
        Ans = (Ans * q) % MOD;
    }
    va_end(va);
    while(Ans < 0) Ans += MOD;
    return Ans;
}
int D1(int n) {
    return (n * (n + 1) / 2) % MOD;
}
int D2(int n) {
    int N1 = n * (n + 1);
    if (N1 % 6 == 0) return ((N1 / 6) % MOD * (2 * n + 1)) % MOD;
    else return (((N1 / 2) % MOD) * (((2 * n + 1) / 3) % MOD)) % MOD;
}
int P(int n, int m) {
    int Ans = 0;
    for (int i = 1; i <= n;) {
        int j = min(m / (m / i), n);
        Ans = add(2, Ans, mul(2, m / i, add(2, D1(j), - D1(i-1))));
        i = j + 1;
    }
    return Ans;
}
int Q(int n, int m) {
    int Ans = 0;
    for (int i = 1; i <= n;) {
        int j = min(min(n / (n / i), m / (m / i)), n);
        Ans = add(2, Ans, mul(3, m / i, n / i, add(2, D2(j), - D2(i-1))));
        i = j + 1;
    }
    return Ans;
}

signed main() {
    int N, M;
    cin >> N >> M;
    if (N > M) swap(N, M);
    int N2 = mul(2, N, N), M2 = mul(2, M, M);
    int Ans = add(5,
            mul(2, add(2, N2, -P(N, N)), add(2, M2, -P(M, M))),
            - mul(3, N, N, M),
            + mul(2, N, P(N, M)),
            + mul(2, M, P(N, N)),
            - Q(N, M));
    while (Ans < 0) Ans += MOD;
    cout << Ans << endl;
}