/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: shaw
 * Time: 2022-03-31 22:35:10
 */
                                     /******************************************************/
#define MULTI_CASE ::SHAW            /* If this problem only has one case. Erase this line */
//#define DEBUG_MODEL ::SHAW         /* If debug for codes. Keep this line                 */
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
vector<int> Q[26];
int tmp[MAXN][26];
string s;
pair<int, int> SSS[MAXN][26];
void cal(int r, int i) {
    if (r < 2) {SSS[r][i].first = SSS[r][i].second = -1; return; }
    int I = upper_bound(Q[i].begin(), Q[i].end(), r) - Q[i].begin();
    if (I < 2) {SSS[r][i].first = SSS[r][i].second = -1; return; }
    SSS[r][i].first = Q[i][I-2], SSS[r][i].second = Q[i][I-1];
}

int dp(int r, int i) {
    if (tmp[r][i] != -1) return tmp[r][i];
    if (r <= 1) return tmp[r][i] = 0;
    if (r == 2) return tmp[r][i] = (s[0] == s[1] && (s[1]-'a' == i)) ? 2 : 0;
    pair<int, int> idx = SSS[r][i];
    if (idx.first == -1 || idx.second == -1) return tmp[r][i] = 0;
    int ans = 0;
    for (int j = 0; j < 26; j++) ans = max(ans, dp(idx.first-1, j) + 2);
    return tmp[r][i] = ans;
}

void solve(int _case) {
    /** Code here for each Case */
    cin >> s;

    int L = s.length();
    for (int i = 0; i <= L; i++) for (int j = 0; j < 26; j++) tmp[i][j] = -1;
    for (int i = 0; i < 26; i++) Q[i].clear();
    for (int i = 0; i < L; i++) Q[s[i]-'a'].pb(i+1);
    for (int r = 1; r <= L; r++) for (int i = 0; i < 26; i++) cal(r, i);

    for (int i = 0; i < 26; i++) tmp[0][i] = tmp[1][i] = 0;
    for (int i = 0; i < 26; i++) tmp[2][i] = (s[0]==s[1] && (s[1]-'a')==i) ? 2 : 0;
    for (int r = 3; r <= L; r++) {
        for (int i = 0; i < 26; i++) {
            int ans = 0;
            pair<int, int> idx = SSS[r][i];
            if (idx.first == -1 || idx.second == -1) tmp[r][i] = 0;
            else {
                for (int j = 0; j < 26; j++) ans = max(ans, dp(idx.first-1, j)+2);
                tmp[r][i] = ans;
            }
        }
    }


    int Ans = 0;
    for (int i = 0; i < 26; i++) {
        Ans = max(Ans, tmp[L][i]);
    }
    cout << (L - Ans) << endl;
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