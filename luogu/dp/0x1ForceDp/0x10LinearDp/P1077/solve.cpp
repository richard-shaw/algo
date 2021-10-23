//
// Created by 走线大师 on 2021/10/10.
//

#include <bits/stdc++.h>

using namespace std;
const int maxn = 105;
const int mod = 1000007;
int tmp[maxn][maxn], a[maxn], n, m;

int dp(int i, int j) {
    if (tmp[i][j] != -1) return tmp[i][j];
    if (i == 1) {
        return tmp[i][j] = j <= a[i] ? 1 : 0;
    } else if (j == 0) {
        return tmp[i][j] = 1;
    } else {
        int sum = 0;
        for (int k = 0; k <= j && k <= a[i]; k++) {
            sum = (sum + dp(i-1, j-k)) % mod;
        }
        return tmp[i][j] = sum;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < maxn; i++) for (int j = 0; j < maxn; j++) tmp[i][j] = -1;
    cout << dp(n, m) << endl;
    return 0;
}