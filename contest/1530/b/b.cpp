/* Generated by powerful Codeforces Tool
 * Author: RichardShaw
 * Time: 2021-09-03 21:38:48
 */

#include<bits/stdc++.h>
using namespace std;
void fast_stream() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define int long long
const int INF = 0x7fffffffffffffff;
const int MAXN = 2e5 + 9;
int mp[22][22], H, W;
pair<int, int> pr[100];
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
bool can_set(int x, int y) {

    if (x < 1 || x > H || y < 1 || y > W) return false;
    if (mp[x][y] == 1) return false;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (mp[nx][ny] == 1) return false;
    }
    return true;
}

void solve () {
    cin >> H >> W;
    memset(mp, 0, sizeof(mp));
    int c = 0;
    for (int i = 1; i < W; i++) pr[c++] = make_pair(1, i);
    for (int i = 1; i < H; i++) pr[c++] = make_pair(i, W);
    for (int i = W; i >= 2; i--) pr[c++] = make_pair(H, i);
    for (int i = H; i >= 2; i--) pr[c++] = make_pair(i, 1);
    for (int i = 0; i < c; i++) {
//        printf("%d %d %d\n", pr[i].first, pr[i].second, can_set(pr[i].first, pr[i].second));
        if (can_set(pr[i].first, pr[i].second)) mp[pr[i].first][pr[i].second] = 1;
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cout << mp[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

signed main() {
    fast_stream();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}