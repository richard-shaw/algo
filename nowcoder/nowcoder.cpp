#include <bits/stdc++.h>

using namespace std;
const int MAXN = 5050;
int sum[MAXN][MAXN];


int main() {
    for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) sum[i][j] = 0;
    int n, r;
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        sum[x][y] = v;
    }

    for (int i = 0; i < MAXN; i++) for (int j = 1; j < MAXN; j++) sum[i][j] += sum[i][j-1];
    for (int j = 0; j < MAXN; j++) for (int i = 1; i < MAXN; i++) sum[i][j] += sum[i-1][j];

    int ans = 0;
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (x-r < 0 || y-r < 0) continue;
            ans = max(ans, sum[x][y] - sum[x][y-r] - sum[x-r][y] + sum[x-r][y-r]);
        }
    }
    cout << ans << endl;
}