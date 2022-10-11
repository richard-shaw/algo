/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: $%U%$
 * Time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
 */
/******************************************************/
//#define MULTI_CASE ::SHAW            /* If this problem only has one case. Erase this line */
#define DEBUG_MODEL ::SHAW         /* If debug for codes. Keep this line                 */
#define SHOW_CASE_USED_TIME ::SHAW /* If need to show used time for case. Keep this line */
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
//#define set(s) set<int> s; s.clear()
//#define map(mp) map<int, int> mp; mp.clear()
#define pb push_back
#define int long long
int ____MOD;
class Solution;
inline int fast_pow(int a, int b) { int base = a, ans = 1; while (b > 0) { if (b & 1) ans = (ans * base) % ____MOD; base = (base * base) % ____MOD; b >>= 1; } return ans; }
inline int inv(int b) { return fast_pow(b, ____MOD-2); }
inline int mod_mul(int a, int b) { return (a * b) % ____MOD; }
inline int mod_div(int a, int b) { return mod_mul(a, inv(b)); }

const int INF9 = 1e9 + 10;
const int INF18 = 1e18 + 10;
const int MOD = ____MOD = 998244353;

const int maxn = 3e4 + 10;
vector<int> E[maxn];
bool _visit[maxn];

void dfs0(int u, vector<int> &vals, int pr, set<int> &vs, multiset<int> &ms) {
    vs.insert(u);
    if (vals[u] > pr) return;
    ms.insert(vals[u]);
    for (int v : E[u]) {
        if (_visit[v]) continue;
        if (vs.find(v) != vs.end()) continue;
        dfs0(v, vals, vals[u], vs, ms);
    }
}
void dfs1(int u, vector<int> &vals, int pr, set<int> &vs, multiset<int> &ms) {
    vs.insert(u);
    if (vals[u] <= pr) return;
    ms.insert(vals[u]);
    for (int v : E[u]) {
        if (_visit[v]) continue;
        if (vs.find(v) != vs.end()) continue;
        dfs1(v, vals, vals[u], vs, ms);
    }
}


int sv(int u, vector<int> &vals) {
    multiset<int> ms1, ms2; ms1.clear(), ms2.clear();
    set<int> vs; vs.clear();
    dfs0(u, vals, vals[u], vs, ms1);
    vs.clear();
    dfs1(u, vals, -1, vs, ms2);

    int ans = 0;
    map<int, int> mpp; mpp.clear();
//    for (int v00 : ms) {
//        if (mpp.find(v00) == mpp.end()) mpp.insert({v00, 1});
//        else mpp[v00]++;
//    }
//
//    for (auto ite : mpp) {
//        int k = ite.second;
//        ans += k * (k-1) / 2;
//    }
    return ans;
}

int dfs(int u, vector<int> &vals) {
    _visit[u] = 1;

    int ans = sv(u, vals);

    for (int v : E[u]) {
        if (_visit[v]) continue;
        ans += dfs(v, vals);
    }
    return ans;
}

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        for (int i = 0; i < n; i++) E[i].clear();
        memset(_visit, 0, sizeof(_visit));
        for (vector<int> &edge : edges) {
            E[edge[0]].push_back(edge[1]);
            E[edge[1]].push_back(edge[0]);
        }

        int ans = n + dfs(0, vals);
        return ans;
    }
};

void solve(int _case) {

    Solution S;
    vector<int> vals; vals.clear();
    vector<vector<int>> edges; edges.clear();

    int v[] = {1,3,2,1,3};
    int e[4][2] = {{0,1},{0,2},{2,3},{2,4}};

    for (int v0 : v) vals.push_back(v0);
    for (int i = 0; i < 4; i++) {
        vector<int> v00; v00.clear();
        v00.push_back(e[i][0]);
        v00.push_back(e[i][1]);
        edges.push_back(v00);
    }

    cout << S.numberOfGoodPaths(vals, edges) << endl;
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