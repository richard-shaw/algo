//
// Created by 走线大师 on 2022/9/15.
//

typedef long long LL;
const int maxn = 1e5 + 10;

struct tree_node {
    int l, r;
    LL lazy;
    LL sum;
    void update(LL lz) {
        lazy += lz;
        sum += lz * (r - l + 1);
    }

} tree[maxn << 2];
LL arr[maxn];

void push_down(int id) {
    if (tree[id].lazy != 0) {
        tree[id << 1].update(tree[id].lazy);
        tree[id << 1 | 1].update(tree[id].lazy);
        tree[id].lazy = 0;
    }
}

void push_up(int id) {
    tree[id].sum = tree[id << 1].sum + tree[id << 1 | 1].sum;
}

void build(int id, int l, int r) {
    tree[id].l = l;
    tree[id].r = r;
    tree[id].lazy = 0;
    if (l == r) {
        tree[id].sum = arr[l];
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
    return s1 + s2;
}