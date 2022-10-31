/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: shaw
 * Time: 2022-10-02 22:35:11
 */
                                     /******************************************************/
#define MULTI_CASE ::SHAW            /* If this problem only has one case. Erase this line */
#define DEBUG_MODEL ::SHAW         /* If debug for codes. Keep this line                 */
//#define SHOW_CASE_USED_TIME ::SHAW /* If need to show used time for case. Keep this line */
                                     /******************************************************/
#ifndef DEBUG_MODEL//::SHAW
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#endif
#include<bits/stdc++.h>

using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define gcd(x, y) __gcd(x, y)
#define lcm(x, y) (x / __gcd(x, y) * y)
#define LL(x) (x << 1)
#define RR(x) (LL(x) | 1)
#define MID(l, r) ((l + r) >> 1)
#define vec(v, p) vector<int> v(p)
#define f_vec(v, p) vector<double> v(p)
#define set(s) set<int> s; s.clear()
#define map(mp) map<int, int> mp; mp.clear()
#define pb push_back
#define int long long
int ____MOD;
inline int fast_pow(int a, int b) { int base = a, ans = 1; while (b > 0) { if (b & 1) ans = (ans * base) % ____MOD; base = (base * base) % ____MOD; b >>= 1; } return ans; }
inline int inv(int b) { return fast_pow(b, ____MOD-2); }
inline int mod_mul(int a, int b) { return (a * b) % ____MOD; }
inline int mod_div(int a, int b) { return mod_mul(a, inv(b)); }

const int INF9 = 1e9 + 10;
const int INF18 = 1e18 + 10;
const int MOD = ____MOD = 998244353;
const int MAXN = 2e5 + 10;

int fa[26], lft;
bool _visit[26];
char nxt[26];

int get_fa(int x) {
    if (x == fa[x]) return x;
    return fa[x] = get_fa(fa[x]);
}
void __union(int x, int y) {
    int fx = get_fa(x), fy = get_fa(y);
    fa[fx] = fy;
}

bool same(int x, int y) { return get_fa(x) == get_fa(y); }

char pick_one(char ch) {
    for (char pk = 'a'; pk <= 'z'; pk++) {
        if (_visit[pk-'a']) continue;
        if (ch == pk) continue;
        if (lft > 1 && same(ch-'a', pk-'a')) continue;
        return pk;
    }
}

void solve(int _case) {
    /** Code here for each Case */
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i < 26; i++) fa[i] = i, nxt[i] = 0, _visit[i] = 0;
    lft = 26;

    for (char ch : s) {
        if (nxt[ch-'a'] != 0) continue;
        else {
            char pk = pick_one(ch);
            _visit[pk-'a'] = 1;
            lft --;
            nxt[ch-'a'] = pk;
            __union(ch-'a', pk-'a');
        }
    }

    string ans = "";
    for (char ch : s) ans += nxt[ch-'a'];
    cout << ans << endl;
}

signed main() {

    FAST_IO
    int t;
#ifdef MULTI_CASE//::SHAW
    cin >> t;
#else
    t = 1;
#endif
    for (int _case = 1; _case <= t; _case++) {
#ifdef SHOW_CASE_USED_TIME//::SHAW
        clock_t t1 = clock();
#endif
        solve(_case);
#ifdef SHOW_CASE_USED_TIME//:SHAW
        clock_t t2 = clock();
        cout << "Case #" << _case << " used: " << ((double)(t2-t1) / CLOCKS_PER_SEC) << "s" << endl;
#endif
    }
}