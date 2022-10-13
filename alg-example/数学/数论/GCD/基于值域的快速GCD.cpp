//
// Created by 走线大师 on 2022/10/13.
//

const int GCD_V = 1000;
const int GCD_V_2 = GCD_V * GCD_V;
// pre 预处理sqrt(N)*sqrt(N)的gcd数组，fac预分解，pri素数数组，isp是否为素数，tot素数个数
int pre[GCD_V+2][GCD_V+2], fac[GCD_V_2+2][3], pri[GCD_V_2+2], isp[GCD_V_2+2], tot = 0;
void init() {
    fac[1][0] = fac[1][1] = fac[1][2] = 1;
    for (int i = 2; i <= GCD_V_2; ++i) {
        if (!isp[i]) {
            fac[i][0] = fac[i][1] = 1;
            fac[i][2] = i;
            pri[++tot] = i;
        }
        for (int j = 1; pri[j] * i <= GCD_V_2; ++j) {
            int tmp = pri[j] * i;
            isp[tmp] = true;
            fac[tmp][0] = fac[i][0] * pri[j];
            fac[tmp][1] = fac[i][1];
            fac[tmp][2] = fac[i][2];
            if (fac[tmp][0] > fac[tmp][1]) {
                fac[tmp][0] ^= fac[tmp][1] ^= fac[tmp][0] ^= fac[tmp][1];
            }
            if (fac[tmp][1] > fac[tmp][2]) {
                fac[tmp][1] ^= fac[tmp][2] ^= fac[tmp][1] ^= fac[tmp][2];
            }
            if (i % pri[j] == 0) {
                break;
            }
        }
    }
    for (int i = 0; i <= GCD_V; ++i) {
        pre[0][i] = pre[i][0] = i;
    }
    for (int i = 1; i <= GCD_V; ++i) {
        for (int j = 1; j <= i; ++j) {
            pre[i][j] = pre[j][i] = pre[j][i % j];
        }
    }
}
int fast_gcd(int a, int b) {
    int ans = 1;
    for (int i = 0; i < 3; ++i) {
        int tmp = (fac[a][i] > GCD_V)
                  ? (b % fac[a][i] ? 1 : fac[a][i])
                  : pre[fac[a][i]][b % fac[a][i]];
        b /= tmp;
        ans *= tmp;
    }
    return ans;
}
