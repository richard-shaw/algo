#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000005
vector<int> v[MAXN], vt;
int arr[MAXN];
int main() {
    for (int i = 0; i < MAXN; i++) v[i].clear();
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        int g = __gcd(n, d);
        for (int i = 1; i <= g; i++) {
            int _i = i;
            for (int j = 1; j <= n / g; j++) {
                v[i].push_back(_i);
                _i += d;
                if (_i > n) _i -= n;
            }
        }
        int Ans = -1;
        for (int i = 1; i <= g; i++) {
            vt.clear();
            vt.push_back(0);
            for (int j = 1; j <= n / g; j++) {
                int s = v[i][j-1];
                if (arr[s] == 0) vt.push_back(j);
            }
            if (vt.size() == 1) { cout << -1 << endl; goto BREAK;}
            for (int j = 1; j < vt.size(); j++) {
                Ans = max(Ans, vt[j] - vt[j-1] - 1);
            }
            if (vt[vt.size() - 1] < n / g) {
                Ans = max(Ans, vt[1] - vt[0] - 1 + n / g - vt[vt.size() - 1]);
            }
        }
        cout << Ans << endl;
        BREAK:;
        for (int i = 1; i <= g; i++) v[i].clear();
    }
}