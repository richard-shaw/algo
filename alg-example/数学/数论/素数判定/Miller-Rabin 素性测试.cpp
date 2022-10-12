//
// Created by 走线大师 on 2022/9/11.
//

/**
 * 时间复杂度O(T(logN)^3), T为测试次数
 * 利用FFT等技术可以优化至 O(T(logN)^2loglogNlogloglogN)
 */

typedef long long int64;
typedef __int128 int128;
const int64 test_time = 10;

inline int64 fast_pow(int64 a, int64 b, int64 mod) {
    int64 ans = 1;
    int128 base = a;
    while (b > 0) {
        if (b & 1) ans = ((int128) ans * base) % mod;
        base = (base * base) % mod;
        b >>= 1;
    }
    return ans;
}


bool millerRabin(int64 n) {
    if (n < 3 || !(n & 1)) return n == 2;
    int64 d = n - 1, r = 0;
    while (!(d & 1)) ++r, d >>= 1;
    for (int64 k = 0; k < test_time; ++k) {
        int64 a = abs(rand()) % (n-2) + 2, x = fast_pow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        for (int i = 0; i < r - 1; ++i) {
            x = (int128)x * x % n;
            if (x == n - 1) break;
        }
        if (x != n-1) return false;
    }
    return true;
}