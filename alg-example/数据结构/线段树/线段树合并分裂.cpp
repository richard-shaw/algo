//
// Created by 走线大师 on 2022/9/18.
//

const int maxn = 2e5 + 10;
typedef long long LL;

struct Node {
    int l, r;
    LL val;
} tree[maxn * 40];
int cnt, root[maxn];
void pushup(int k) { tree[k].val = tree[tree[k].l].val + tree[tree[k].r].val; }
void modify(int &k, int l, int r, int p, int x) {
    if (!k) k = ++cnt;
    tree[k].val += x;
    if (l == r) return;
    int m = (l + r) >> 1;
    if (p <= m) modify(tree[k].l, l, m, p, x);
    else modify(tree[k].r, m+1, r, p, x);
}

void merge(int &x, int y) {
    if (!x || !y) x |= y;
    else {
        tree[x].val += tree[y].val;
        merge(tree[x].l, tree[y].l);
        merge(tree[x].r, tree[y].r);
    }
}

int split(int &k, int l, int r, int x, int y) {
    int n = ++cnt;
    if (x <= l && r <= y) {
        tree[n] = tree[k];
        k = 0;
    } else {
        int mid = (l + r) >> 1;
        if (x <= mid) tree[n].l = split(tree[k].l, l, mid, x, y);
        if (y > mid) tree[n].r = split(tree[k].r, mid+1, r, x, y);
        pushup(k);
        pushup(n);
    }
    return n;
}