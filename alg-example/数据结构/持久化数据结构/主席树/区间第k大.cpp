//
// Created by 走线大师 on 2022/9/15.
//

const int maxn = 1e5 + 10;
int cnt = 0, root[maxn], a[maxn];

struct node {
    int l, r, lid, rid, sum;
} T[maxn * 40];

int init(int l, int r) {
    int cur = ++cnt;
    T[cur].l = l, T[cur].r = r, T[cur].sum = 0;
    if (l == r) {
        T[cur].lid = T[cur].rid = -1;
        return cnt;
    }
    int mid = (l + r) >> 1;
    T[cur].lid = init(l, mid);
    T[cur].rid = init(mid+1, r);
    return cnt;
}

void update(int l, int r, int pr, int &cur, int pos) {
    T[++cnt] = T[pr], T[cnt].sum++, cur = cnt;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid) update(l, mid, T[pr].lid, T[cur].lid, pos);
    else update(mid + 1, r, T[pr].rid, T[cur].rid, pos);
}

int query(int l, int r, int x, int y, int k) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int sum = T[T[y].lid].sum - T[T[x].lid].sum;
    if (sum >= k) return query(l, mid, T[x].lid, T[y].lid, k);
    else return query(mid + 1, r, T[x].rid, T[y].rid, k - sum);
}