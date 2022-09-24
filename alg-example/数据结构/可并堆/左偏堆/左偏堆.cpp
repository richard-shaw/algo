//
// Created by 走线大师 on 2022/9/24.
//
const int maxn = 1e5 + 9;

struct Node {
    int l, r, val, dis;
} T[maxn];
#define ls(x) T[x].l
#define rs(x) T[x].r

int merge(int x, int y) {
    if (!x || !y) return x+y;
    if (T[x].val > T[y].val) swap(x, y);
    rs(x) = merge(rs(x), y);
    if (T[ls(x)].dis < T[rs(x)].dis) swap(ls(x), rs(x));
    T[x].dis = T[rs(x)] + 1;
    return x;
}

void pop(int x) {
    merge(ls(x), rs(x));
}