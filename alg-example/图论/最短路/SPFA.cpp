//
// Created by 走线大师 on 2022/9/9.
//

/**
 * 单源最短路
 * 任意图
 * 能检测负环
 * 中/小图
 * 时间复杂度O(NM)
 */

const int maxn = 1e4 + 10;
vector<pair<int, int>> E[maxn];
int dis[maxn], inq[maxn];

void func(int n, int m, int s) {
    queue<int> Q;
    while (!Q.empty()) Q.pop();
    for (int i = 1; i <= n; i++) dis[i] = 1e9, inq[i] = 0;
    dis[s] = 0;
    Q.push(s), inq[s] = 1;

    while (!Q.empty()) {
        int u = Q.front(); Q.pop(); inq[u] = 0;

        for (int i = 0; i < E[u].size(); i++) {
            int v = E[u][i].first, w = E[u][i].second;

            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!inq[v]) {
                    inq[v] = 1;
                    Q.push(v);
                }
            }
        }
    }
}