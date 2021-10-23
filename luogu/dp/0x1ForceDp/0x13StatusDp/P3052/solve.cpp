//
// Created by 走线大师 on 2021/10/20.
//

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1 << 18;
int N, W, f[MAXN], g[MAXN], a[20];

int main() {
    for (int i = 0; i < MAXN; i++) f[i] = 1e9;
    cin >> N >> W;
    for (int i = 1; i <= N; i++) cin >> a[i];
    f[0] = 1, g[0] = W;
    for (int s = 0; s < (1 << N); s++) {
        for (int j = 1; j <= N; j++) {
            if (s & (1 << (j-1))) continue;
            if (g[s] >= a[j] && f[s | (1 << (j - 1))] >= f[s]) {
                f[s | (1 << (j-1))] = f[s];
                g[s | (1 << (j-1))] = g[s] - a[j];
            } else if (g[s] < a[j] && f[s | (1 << (j - 1))] >= f[s] + 1){
                f[s | (1 << (j - 1))] = f[s] + 1;
                g[s | (1 << (j - 1))] = max(g[s | (1 << (j - 1))], W - a[j]);
            }
        }
    }
    cout << f[(1 << N) - 1] << endl;
}