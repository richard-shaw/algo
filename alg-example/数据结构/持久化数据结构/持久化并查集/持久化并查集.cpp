//
// Created by 走线大师 on 2022/9/24.
//

const int maxn = 2e5 + 10;

struct Node {
    int l, r, val;
} T[maxn * 80];
int cnt, rootfa[maxn], rootdep[maxn], n;

void build(int l, int r, int &now) {
    now = ++cnt;
    if (l == r) {
        T[now].val = l;
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, T[now].l);
    build(m+1, r, T[now].r);
}

void modify(int l, int r, int ver, int &now, int pos, int val) {
    T[now=++cnt] = T[ver];
    if (l == r) {
        T[now].val = val;
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m) modify(l, m, T[ver].l, T[now].l, pos, val);
    else modify(m+1, r, T[ver].r, T[now].r, pos, val);
}

int query(int l, int r, int now, int pos) {
    if (l == r) return T[now].val;
    int m = (l + r) >> 1;
    if (pos <= m) return query(l, m, T[now].l, pos);
    else return query(m+1, r, T[now].r, pos);
}

int find(int ver, int x) {
    int fx = query(1, n, rootfa[ver], x);
    return fx == x ? x : find(ver, fx);
}

void merge(int ver, int x, int y) {
    x = find(ver-1, x), y = find(ver-1, y);
    if (x == y) {
        rootfa[ver] = rootfa[ver-1];
        rootdep[ver] = rootfa[ver-1];
    } else {
        int depx = query(1, n, rootdep[ver-1], x);
        int depy = query(1, n, rootdep[ver-1], y);
        if (depx < depy) {
            modify(1, n, rootfa[ver-1], rootfa[ver], x, y);
            rootdep[ver] = rootdep[ver-1];
        } else if (depx > depy) {
            modify(1, n, rootfa[ver-1], rootfa[ver], y, x);
            rootdep[ver] = rootdep[ver-1];
        } else {
            modify(1, n, rootfa[ver-1], rootfa[ver], x, y);
            modify(1, n, rootdep[ver-1], rootdep[ver], y, depy + 1);
        }
    }
}
