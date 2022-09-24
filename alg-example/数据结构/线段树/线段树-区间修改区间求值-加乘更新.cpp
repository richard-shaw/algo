//
// Created by 走线大师 on 2022/9/18.
//

typedef long long LL;
const int maxn = 1e5 + 10;
int mod;

LL arr[maxn];
struct node {
    int l, r;
    LL lazy_mul, lazy_add, sum;
    void update(int type, LL v) {
        if (type == 1) {
            // 乘法更新
            lazy_mul = (lazy_mul * v) % mod;
            lazy_add = (lazy_add * v) % mod;
            sum = (sum * v) % mod;
        } else {
            // 加法更新
            lazy_add = (lazy_add + v) % mod;
            sum = (sum + v * (r - l + 1)) % mod;
        }
    }
    int mid() { return (l + r) >> 1; }
} T[maxn << 2];

void push_up(int id) {
    T[id].sum = T[id<<1].sum + T[id<<1|1].sum;
}

void push_down(int id) {
    if (T[id].lazy_mul != 1) {
        T[id<<1].update(1, T[id].lazy_mul);
        T[id<<1|1].update(1, T[id].lazy_mul);
        T[id].lazy_mul = 1;
    }
    if (T[id].lazy_add != 0) {
        T[id<<1].update(2, T[id].lazy_add);
        T[id<<1|1].update(2, T[id].lazy_add);
        T[id].lazy_add = 0;
    }
}

void build(int id, int l, int r) {
    T[id].l = l, T[id].r = r, T[id].lazy_add = 0, T[id].lazy_mul = 1;
    if (l == r) T[id].sum = arr[l] % mod;
    else {
        int m = (l + r) >> 1;
        build(id<<1, l, m);
        build(id<<1|1, m + 1, r);
        push_up(id);
    }
}

void update(int id, int l, int r, int type, LL v) {
    if (l <= T[id].l && T[id].r <= r) T[id].update(type, v);
    else {
        push_down(id);
        int m = T[id].mid();
        if (l <= m) update(id<<1, l, r, type, v);
        if (r > m) update(id<<1|1, l, r, type, v);
        push_up(id);
    }
}

LL query(int id, int l, int r) {
    if (l <= T[id].l && T[id].r <= r) return T[id].sum;
    push_down(id);
    int m = T[id].mid();
    LL s1 = 0, s2 = 0;
    if (l <= m) s1 = query(id<<1, l, r);
    if (r > m) s2 = query(id<<1|1, l, r);
    return (s1 + s2) % mod;
}