//
// Created by 走线大师 on 2022/9/24.
//

#define MAX_N 2000005
int d[MAX_N][32];
int lg[MAX_N];
void init(int n) {
    for (int len = 1; len <= n; len ++) {
        int k = 0;
        while ((1 << (k + 1)) <= len) k++;
        lg[len] = k;
    }
    // 需要初始化d[i][0];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i <= n; i++) {
            d[i][j] = max(d[i][j-1], d[i + (1<<(j-1))][j-1]);
        }
    }

}