/**
 * Life means frustration eight or nine times out of ten.
 * And dwell one or two.
 *
 * Author: shaw
 * Time: 2022-05-02 22:35:05
 */
/******************************************************/
//#define MULTI_CASE ::SHAW            /* If this problem only has one case. Erase this line */
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

int A[MAXN], M[MAXN];
void judge(int &ans, int X, int Y, int i) {
    if (2*X+Y >= A[i] && 2*Y+X >= A[i+1]) {
        ans = min(ans, X+Y);
    }
}
void solve(int _case) {
    /** Code here for each Case */
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    M[N+1] = 1e9;
    for (int i = N; i >= 1; i--) {
        M[i] = min(A[i], M[i+1]);
    }
    int ans = 1e9;

    // only 1
    for (int i = 2; i <= N-1; i++) {
        int step[] = {(A[i]+1)/2, A[i-1], A[i+1]};
        sort(step, step+3);
        ans = min(ans, step[1]);
    }
    ans = min(ans, max((A[1]+1)/2, A[2]));
    ans = min(ans, max((A[N]+1)/2, A[N-1]));

    // i && i + 1
    for (int i = 1; i < N; i++) {
        if (2*A[i] <= A[i+1]) ans = min(ans, (A[i+1]+1)/2);
        else if (2*A[i+1] <= A[i]) ans = min(ans, (A[i]+1) / 2);
        else {
            int X = 2*A[i]-A[i+1], Y = 2*A[i+1]-A[i];
//            ans = min(ans, X/3+Y/3+(X%3!=0 || Y%3!=0));
            judge(ans, X/3, Y/3, i);
            judge(ans, X/3+1, Y/3, i);
            judge(ans, X/3+1, Y/3+1, i);
            judge(ans, X/3, Y/3+1, i);
//            if (2*X+Y >= A[i] && X+2*Y >= A[i+1]) ans = min(ans, X+Y);
//            if (2*(X+1)+Y)
        }
    }
    // i && i + 2
    for (int i = 2; i < N; i++) {
        int x1 = (A[i-1]+1)/2, y1 = (A[i+1]+1)/2;
        if (x1+y1 > A[i]) {
            ans = min(ans,
                      min(A[i] >= x1 ? A[i] : x1,
                          A[i] >= y1 ? A[i] : y1));
        }
        else ans = min(ans, x1+y1);
        if (i > 2) {
            if (A[i-2] < x1) ans = min(ans, y1+A[i-2]);
        }
        if (i < N-1) {
            if (A[i+2] < y1) ans = min(ans, x1+A[i+2]);
        }
    }
    // i && i + k (k >= 3)
    for (int i = 1; i <= N-3; i++) {
        ans = min(ans, (A[i]+1)/2 + (M[i+3]+1) / 2);
    }
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