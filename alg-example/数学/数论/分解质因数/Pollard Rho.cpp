//
// Created by 走线大师 on 2022/9/11.
//
typedef long long int64;
typedef __int128 int128;
const int64 test_time = 10;

int64 __gcd__(int64 a, int64 b) {
    return b == 0 ? a : __gcd__(b, a % b);
}

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

int64 pollardPho(int64 x) {
    int64 s = 0, t = 0;
    int64 c = (int64) abs(rand()) % (x - 1) + 1;
    int step = 0, goal = 1;
    int64 val = 1;
    for (goal = 1;;goal <<= 1, s = t, val = 1) {
        for (step = 1; step <= goal; ++step) {
            t = ((int128) t* t + c) % x;
            val = (int128) val * abs(t-s) % x;
            if ((step % 127) == 0) {
                int64 d = __gcd__(val, x);
                if (d > 1) return d;
            }
        }
        int64 d = __gcd__(val, x);
        if (d > 1) return d;
    }
}

void get_max(int64 x, int64 &ans) {
    if (x <= ans || x < 2) return;
    if (millerRabin(x)) {
        ans = max(ans, x);
        return;
    }
    int64 p = x;
    while (p >= x) p = pollardPho(x);
    while ((x % p) == 0) x /= p;
    get_max(x, ans);
    get_max(p, ans);
}