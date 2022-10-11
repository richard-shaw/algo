/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: shaw
 * Time: 2022-05-26 01:35:11
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
vector<string> sp;

void solve(int _case) {
    /** Code here for each Case */
    int a, b, c, d;
    string S;
    cin >> a >> b >> c >> d;
    cin >> S;
    int ca = 0, cb = 0, L = S.length();
    if (a + b + 2 * c + 2 * d != L) { cout << "NO" << endl; return; }
    for (int i = 0; i < L; i++) if (S[i] == 'A') ca++; else cb++;
    if (ca != (a + c + d)) { cout << "NO" << endl; return; }
    if (cb != (b + c + d)) { cout << "NO" << endl; return; }
    sp.clear();
    char bf = '#';
    int pi = 0;
    for (int i = 0; i < L; i++) {
        if (S[i] == bf) {
            if (i - pi > 1) {
                string tmp = S.substr(pi, i - pi);
                sp.push_back(tmp);
            }
            pi = i;
        }
        else bf = S[i];
    }
    if (L - pi > 1) {
        sp.push_back(S.substr(pi, L - pi));
    }

    int all_match = 0, tab = 0, tba = 0;
    for (string sp0 : sp) {
        int lll = sp0.length();
        if (lll % 2 == 1) all_match += lll / 2;
        else {
            all_match += (lll / 2 - 1);
            if (sp0[0] == 'A') tab++;
            else tba ++;
        }
    }
    int minx = c - tab;
    if (minx < 0) { cout << "NO" << endl; return;}
    if (all_match - minx + tba >= d) { cout << "YES" << endl; return; }
    else cout << "NO" << endl;

//    cout << "Not sure; ";
//    for (string s : sp) cout << s << ',';
//    cout << endl;
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