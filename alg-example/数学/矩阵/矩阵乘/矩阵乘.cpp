//
// Created by 走线大师 on 2022/9/13.
//

int mod;
const int __MAT_SIZE = 100;
struct Mat {
    int n, m;
    int v[__MAT_SIZE][__MAT_SIZE];
    Mat() {
        for (int i = 0; i < __MAT_SIZE; i++) for (int j = 0; j < __MAT_SIZE; j++) v[i][j] = 0;
    }
};

Mat mul(Mat &a, Mat &b) {
    Mat ans;
    ans.n = a.n, ans.m = b.m;
    for (int i = 1; i <= a.n; i++) {
        for (int k = 1; k <= a.m; k++) {
            if (a.v[i][k] == 0) continue;
            for (int j = 1; j <= b.m; j++) {
                ans.v[i][j] = (ans.v[i][j] + (a.v[i][k] * b.v[k][j]) % mod) % mod;
            }
        }
    }
    return ans;
}
