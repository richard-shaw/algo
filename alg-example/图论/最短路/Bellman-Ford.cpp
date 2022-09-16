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

const int maxn = 2e5;

struct Edge {
    int from, to, cost;
} edges[maxn];

int dis[maxn];
void fun(int n, int m, int s) {
    for (int i = 1; i <= n; i++) dis[i] = 1e9;
    dis[s] = 0;

    for (int i = 1; i <= n; i++) {
        bool update = false;
        for (int i = 0; i < m; i++) {
            Edge &e = edges[i];
            if (dis[e.from] != 1e9 && dis[e.to] > dis[e.from] + e.cost) {
                update = true;
                dis[e.to] = dis[e.from] + e.cost;
            }
        }
        if (!update) break;
    }

}