//
// Created by 走线大师 on 2021/9/11.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn = 1e6 + 3;
int visit[maxn], prime[maxn], mu[maxn], phi[maxn], tot = 0;
map<int, int> tp1, tp2;
void init() {
    tp1.clear(), tp2.clear();
    memset(visit, 0, sizeof(visit));
    mu[1] = 1, phi[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (visit[i] == 0) prime[++tot] = i, mu[i] = -1, phi[i] = i-1;
        for (int j = 1; j <= tot; j++) {
            if (i * prime[j] >= maxn) break;
            visit[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                phi[i * prime[j]] = prime[j] * phi[i];
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
                phi[i * prime[j]] = phi[i] * phi[prime[j]];
            }
        }
    }
    for (int i = 2; i < maxn; i++) {
        mu[i] += mu[i-1];
        phi[i] += phi[i-1];
    }
}

int S2(int n) {
    if (n == 1) return 1;
    if (n < maxn) return mu[n];
    if (tp2.find(n) != tp2.end()) return tp2[n];
    int Ans = 0;
    for (int i = 2; i <= n;) {
        int j = n / (n / i);
        Ans += S2(n / i) * (j-i+1);
        i = j + 1;
    }
    Ans = 1 - Ans;
    return tp2[n] = Ans;
}

int S1(int n) {
    if (n == 1) return 1;
    if (n < maxn) return phi[n];
    if(tp1.find(n) != tp1.end()) return tp1[n];
    int Ans = 0;
    for (int i = 2; i <= n;) {
        int j = n / (n / i);
        Ans += S1(n / i) * (j-i+1);
        i = j + 1;
    }
    Ans = n * (n + 1) / 2 - Ans;
    return tp1[n] = Ans;
}

signed main() {
    init();
    int T, n;
    cin >> T;
    while(T--) {
        cin >> n;
        cout << S1(n) << ' ' << S2(n) << endl;
    }
}