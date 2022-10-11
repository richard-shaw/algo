/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-12-03 22:13:10
 */
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;
void fast_stream() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define int long long
const int INF = 0x7fffffffffffffff;
const int MAXN = 2e7 + 4;
int cnt[MAXN], tmp[MAXN], N, C, Ans, prime_cnt = 0, prime[MAXN], visit[MAXN], is_prime[MAXN];

int dp(int i) {
    if (~tmp[i]) return tmp[i];
    int ans = i * cnt[i];
    for (int c = 1; c <= prime_cnt && i * prime[c] <= C ; c++) {
        int k = prime[c];
        ans = max(ans, dp(i * k) + i * (cnt[i] - cnt[i * k]));
    }
    return tmp[i] = ans;
}

void init() {
    memset(is_prime, 0, sizeof(is_prime));
    memset(visit, 0, sizeof(visit));
    for (int i = 2; i < MAXN; i++) {
        if (visit[i] == 0) prime[++prime_cnt] = i, is_prime[i] = 1;
        for (int j = 1; j <= prime_cnt && i * prime[j] < MAXN; j++) {
            visit[i * prime[j]] = 1;
        }
    }
}

signed main() {
//    clock_t t1 = clock();
    init();
//    clock_t t3 = clock();
//    cout << (double) (t3-t1) / CLOCKS_PER_SEC << endl;
//    fast_stream();
//    cin >> N;
    scanf("%lld", &N);
//N = 100000;
    C = 0, Ans = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(tmp, -1, sizeof(tmp));
    for (int i = 1; i <= N; i++) {
        int x;
//        cin >> x;
        scanf("%lld", &x);
//        x = 17207280;
        C = max(C, x);
        if (is_prime[x]) {
            cnt[x]++;
            cnt[1]++;
            continue;
        }
        for (int k = 1; k * k <= x; k++) {
            if (x % k == 0) {
                cnt[k]++;
                if (k * k != x) cnt[x / k]++;
            }
        }
    }
//    clock_t t2 = clock();
//    cout << (double)(t2 - t1) / CLOCKS_PER_SEC << endl;
    for (int i = C; i >= 1; i--) Ans = max(Ans, dp(i));
//    clock_t tx = clock();
//    cout << (double) (tx - t1) / CLOCKS_PER_SEC << endl;
//    cout << Ans << endl;
    printf("%lld\n", Ans);
}