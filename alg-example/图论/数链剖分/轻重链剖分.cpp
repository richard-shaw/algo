//
// Created by 走线大师 on 2022/9/18.
//

/**
 * 其中add中的update函数需要自己实现，常用线段树、树状数组等
 * 树链剖分的查询操作和add函数类似，仅加了求和、返回步骤
 */

vector<int> E[maxn];
int rnk[maxn], tot = 0;
struct Info {
    int father, deep, size, hson, top, dfn;
} info[maxn];

void dfs1(int u, int fa, int dp) {
    info[u].father = fa;
    info[u].deep = dp;
    info[u].size = 1;
    info[u].hson = -1;

    int mx = 0;
    for (int v : E[u]) {
        if (v == fa) continue;
        dfs1(v, u, dp+1);
        info[u].size += info[v].size;
        if (mx < info[v].size) mx = info[v].size, info[u].hson = v;
    }
}

void dfs2(int u, int top) {
    info[u].top = top;
    info[u].dfn = ++tot;
    rnk[tot] = u;

    if (info[u].hson != -1) dfs2(info[u].hson, top);
    for (int v : E[u]) {
        if(v == info[u].father) continue;
        if (v != info[u].hson) dfs2(v, v);
    }
}

void add(int u, int v, int x) {
    while (info[u].top != info[v].top) {
        if (info[info[u].top].deep < info[info[v].top].deep) swap(u, v);
        update(1, info[u].dfn, info[info[u].top].dfn, x);
        u = info[info[u].top].father;
    }

    int l = info[u].dfn, r = info[v].dfn;
    if (l > r) swap(l, r);
    update(1, l, r, x);
}
