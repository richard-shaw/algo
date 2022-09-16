//
// Created by 走线大师 on 2022/9/16.
//

const int maxn = 2e4 + 10;

int a[maxn];
inline int low_bit(int x) { return x & (-x); }
int query (int pos) {
    int ans = 0;
    while (pos > 0) ans += a[pos], pos -= low_bit(pos);
    return ans;
}
void update(int pos, int x) {
    while (pos < maxn) a[pos] += x, pos += low_bit(pos);
}