//
// Created by 走线大师 on 2022/9/9.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
int dis[103][103], used[103], d[103];

int main() {
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> dis[i][j];
        for (int i = 1; i <= n; i++) d[i] = 1e9, used[i] = 0;

        d[1] = 0;
        int ans = 0;

        while (true) {
            int v = -1;
            for (int u = 1; u <= n; u++) {
                if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
            }
            if (v == -1) break;
            used[v] = 1;
            ans += d[v];
            for (int u = 1; u <= n; u++) {
                d[u] = min(d[u], dis[v][u]);
            }
        }
        cout << ans << endl;
    }
}