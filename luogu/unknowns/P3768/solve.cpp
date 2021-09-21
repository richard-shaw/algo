//
// Created by 走线大师 on 2021/9/11.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn = 1e6+5;
map<int, int> tp;
int visit[maxn], prime[maxn], phi[maxn], tot = 0, P, N;
void init() {
    tp.clear();
    memset(visit, 0, sizeof(visit));
    phi[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (visit[i] == 0) prime[++tot] = i, phi[i] = i-1;
        for (int j = 1; j <= tot; j++) {
            if (prime[j] * i >= maxn) break;
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            }
        }
    }
    for (int i = 2; i < maxn; i++) {
        phi[i] = (phi[i-1] + i * i * phi[i]) % P;
    }
}
int S_i_1(int n) {
    return (n * (n+1) / 2) % P;
}
int S_i_2(int n) {
    return (n * (n+1) * (2*n+1) / 6) % P;
}
int S_i_3(int n) {
    return (S_i_1(n) * S_i_1(n)) % P;
}
int S(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n < maxn) return phi[n];
    if (tp.find(n) != tp.end()) return tp[n];
    int Ans = 0;
    for (int i = 2; i <= n;) {
        int j = n / (n / i);
        Ans = (Ans + S(n / i) * (S_i_2(j)-S_i_2(i-1))) % P;
        i = j + 1;
    }
    return tp[n] = (S_i_3(n) - Ans) % P;
}

signed main() {
    tp.clear();
    cin >> P >> N;
    int Ans = 0;
    for (int i = 1; i <= N;) {
        int j = N / (N / i);
        Ans = (Ans + S_i_3(N / i) * (S(j) - S(i-1))) % P;
        i = j + 1;
    }
    if (Ans < 0) Ans += P;
    cout << Ans << endl;
}