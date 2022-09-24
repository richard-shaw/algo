//
// Created by 走线大师 on 2022/9/18.
//

typedef long long LL;

const int maxn = 1e5 + 10;
LL arr[maxn], mod;
int rnk[maxn], tot = 0;
vector<int> E[maxn];
struct tree_node {
    int l, r;
    LL lazy;
    LL sum;
    void update(LL lz) {
        lazy = (lazy + lz) % mod;
        sum = (sum + (lz * (r - l + 1)) % mod) %mod;
    }

} tree[maxn << 2];

void push_down(int id) {
    if (tree[id].lazy != 0) {
        tree[id << 1].update(tree[id].lazy);
        tree[id << 1 | 1].update(tree[id].lazy);
        tree[id].lazy = 0;
    }
}

void push_up(int id) {
    tree[id].sum = (tree[id << 1].sum + tree[id << 1 | 1].sum) % mod;
}

void build(int id, int l, int r) {
    tree[id].l = l;
    tree[id].r = r;
    tree[id].lazy = 0;
    if (l == r) {
        tree[id].sum = arr[rnk[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    push_up(id);
}

void update(int id, int l, int r, LL x) {
    if (l <= tree[id].l && tree[id].r <= r) {
        tree[id].update(x);
        return;
    }
    push_down(id);
    int mid = (tree[id].l + tree[id].r) >> 1;
    if (l <= mid) update(id<<1, l, r, x);
    if (r > mid) update(id<<1|1, l, r, x);
    push_up(id);
}

LL query(int id, int l, int r) {
    if (l <= tree[id].l && tree[id].r <= r) return tree[id].sum;
    push_down(id);
    int mid = (tree[id].l + tree[id].r) >> 1;
    LL s1 = 0, s2 = 0;
    if (l <= mid) s1 = query(id<<1, l, r);
    if (r > mid) s2 = query(id<<1|1, l, r);
    push_up(id);
    return (s1 + s2) % mod;
}

struct node {
    int father, deep, size, hson, top, in_dfn, out_dfn;
} nodes[maxn];

void dfs1(int u, int fa, int deep) {
    nodes[u].father = fa;
    nodes[u].deep = deep;
    nodes[u].size = 1;
    nodes[u].hson = -1;

    int mx = 0;
    for (int v : E[u]) {
        if (v == fa) continue;
        dfs1(v, u, deep+1);
        nodes[u].size += nodes[v].size;
        if (mx < nodes[v].size) mx = nodes[v].size, nodes[u].hson = v;
    }
}

void dfs2(int u, int top) {
    nodes[u].top = top;
    nodes[u].in_dfn = ++ tot;
    rnk[tot] = u;
    if (nodes[u].hson != -1) dfs2(nodes[u].hson, top);
    for (int v : E[u]) {
        if (v == nodes[u].father) continue;
        if (v != nodes[u].hson) dfs2(v, v);
    }
    nodes[u].out_dfn = tot;
}

void update_edge(int u, int v, LL x) {
    while (nodes[u].top != nodes[v].top) {
        if (nodes[nodes[u].top].deep < nodes[nodes[v].top].deep) swap(u, v);
        update(1, nodes[nodes[u].top].in_dfn, nodes[u].in_dfn, x);
        u = nodes[nodes[u].top].father;
    }
    int du = nodes[u].in_dfn, dv = nodes[v].in_dfn;
    if (du > dv) swap(du, dv);
    update(1, du, dv, x);
}

LL query_edge(int u, int v) {
    LL ans = 0;
    while (nodes[u].top != nodes[v].top) {
        if (nodes[nodes[u].top].deep < nodes[nodes[v].top].deep) swap(u, v);
        ans = (ans + query(1, nodes[nodes[u].top].in_dfn, nodes[u].in_dfn)) % mod;
        u = nodes[nodes[u].top].father;
    }
    int du = nodes[u].in_dfn, dv = nodes[v].in_dfn;
    if (du > dv) swap(du, dv);
    ans = (ans + query(1, du, dv)) % mod;
    while (ans < 0) ans += mod;
    while (ans >= mod) ans -= mod;
    return ans;
}
