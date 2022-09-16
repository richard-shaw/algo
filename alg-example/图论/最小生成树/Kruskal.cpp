//
// Created by 走线大师 on 2022/9/9.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 2e4 + 10;
struct Edge {
    int from, to, cost;
    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

bool cmp(Edge &e1, Edge &e2) {
    return e1.cost < e2.cost;
}

int fa[1003];
int get_fa(int x) {
    if (x == fa[x]) return x;
    return fa[x] = get_fa(fa[x]);
}
void _union(int x, int y) {
    int fx = get_fa(x), fy = get_fa(y);
    fa[fx] = fy;
}
bool same(int x, int y) {
    return get_fa(x) == get_fa(y);
}

vector<Edge> E;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    E.clear();
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        E.push_back(Edge(u, v, -c));
    }
    sort(E.begin(), E.end(), cmp);

    int ans = 0;
    for (int i = 0; i < m; i++) {
        Edge &e = E[i];
        if (same(e.from, e.to)) continue;
        ans += e.cost;
        _union(e.from, e.to);
    }

    bool ok = true;
    for (int i = 2; i <= n; i++) {
        if (!same(1, i)) {ok = false; break; }
    }
    if (!ok) cout << -1 << endl;
    else cout << -ans << endl;
}