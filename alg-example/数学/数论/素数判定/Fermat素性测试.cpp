//
// Created by 走线大师 on 2022/9/11.
//

/**
 * 判断依据为费马小定理：
 *    如果gcd(a, n) == 1 那么pow(a, n-1) % n = 1
 * 随机选择 [2, n-1]的数a，判断是否满足上述等式，如果不满足，那么gcd(a, n) != 1, 即n为合数
 *
 * 该方法不能保证正确率，因为存在n是合数但依然满足上述等式，这种n称作伪素数
 * 且对于卡迈克尔数(Carmichael Number)n，所有的a∈[2,n-1]均满足上述等式且n为合数
 *
 * 时间复杂度O(TlogN) T为测试次数
 */

const int test_time = 15;
inline int fast_pow(int a, int b, int mod) {
    int ans = 1, base = a;
    while (b > 0) {
        if (b & 1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        b >>= 1;
    }
    return ans;
}

bool fermat(int n) {
    if (n < 3) return n == 2;
    // test_time为测试次数，建议设置不小于8的整数以保证正确率，但不宜过大，否则影响效率
    for (int i = 1; i <= test_time; ++i) {
        int a = abs(rand()) % (n-2) + 2;
        if (fast_pow(a, n-1, n) != 0) return false;
    }
    return true;
}