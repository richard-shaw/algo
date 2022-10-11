//
// Created by Shaw on 2022/10/2.
//


class Hamel {
private:
    typedef long long LL;
    LL p[64], tmp[64];
    bool has_zero;
public:
    inline void clear() {
        memset(p, 0, sizeof(p));
        memset(tmp, 0, sizeof(tmp));
        has_zero = false;
    }
    Hamel() { clear(); }
    inline void insert(LL x) {
        if (x == 0ll) { has_zero = true; return; }
        for (register int i = 62; ~i; --i) {
            if (!(x >> i)) continue;
            if (!p[i]) {
                p[i] = x;
                break;
            }
            x ^= p[i];
        }
    }
    inline bool can_build(LL x) {
        for (register int i = 62; ~i; --i) {
            if (!(x >> i)) continue;
            if (!p[i]) return false;
            else x ^= p[i];
        }
        return true;
    }
    inline LL query_max() {
        LL ans = 0ll;
        for (register int i = 62; ~i; --i) ans = max(ans, ans ^ p[i]);
        return ans;
    }
    inline LL query_min() {
        if (has_zero) return 0ll;
        for (register int i = 0; i <= 62; i++) if (p[i]) return p[i];
        return 0ll;
    }
    inline LL kth(LL k) {
        LL res = 0;
        int cnt = 0;
        k -= has_zero; if (!k) return 0;
        for (register int i = 0; i <= 62; i++) {
            for (int j = i - 1; ~j; --j) {
                if (p[i] & (1ll << j)) p[i] ^= p[j];
            }
            if (p[i]) tmp[cnt++] = p[i];
        }
        if (k >= (1ll << cnt)) return -1ll;
        for (register int i = 0; i < cnt; i++) if (k & (1ll << i)) res ^= tmp[i];
        return res;
    }
};