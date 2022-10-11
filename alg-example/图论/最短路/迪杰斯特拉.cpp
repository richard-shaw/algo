//
// Created by 走线大师 on 2022/9/9.
//

/**
 * 单源最短路
 * 任意图
 * 不能检测负环
 * 大/中图
 * 时间复杂度O(M logM)
 */

const int maxn = 1e4 + 10;
vector<pair<int, int>> E[maxn];
int dis[maxn];

void func(int n, int m, int s) {
    priority_queue<pair<int, int>> Q;
    while (!Q.empty()) Q.pop();
    for (int i = 1; i <= n; i++) dis[i] = 1e9;
    dis[s] = 0;
    Q.push({ -dis[s], s });

    while (!Q.empty()) {
        int u = Q.top().second, d = -Q.top().first; Q.pop();
        if (dis[u] != d) continue;
        for (int i = 0; i < E[u].size(); i++) {
            int v = E[u][i].first, w = E[u][i].second;

            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                Q.push({ -dis[v], v });
            }
        }
    }
}