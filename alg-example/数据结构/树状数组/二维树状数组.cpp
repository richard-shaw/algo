//
// Created by 走线大师 on 2022/9/17.
//

/**
 * 单点更新，区间查询
 */
/**
 * 如果需要单点查询，区间更新，做二维差分数组： d[x][y] = a[x][y] + a[x-1][y-1] - a[x][y-1] - a[x-1][y]
 * query(x, y)返回a[x][y]的单点值
 */

const int maxn = 1050;
int BIT[maxn][maxn];
inline int low_bit(int x) { return x & (-x); }

void add(int x, int y, int v) {
    int y0 = y;
    while (x < maxn) {
        y = y0;
        while (y < maxn) {
            BIT[x][y] += v;
            y += low_bit(y);
        }
        x += low_bit(x);
    }
}

int query(int x, int y) {
    int y0 = y, ans = 0;
    while (x > 0) {
        y = y0;
        while (y > 0) {
            ans += BIT[x][y];
            y -= low_bit(y);
        }
        x -= low_bit(x);
    }
    return ans;
}
