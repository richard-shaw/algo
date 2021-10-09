//
// Created by 走线大师 on 2021/10/10.
//

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1003;
typedef struct _Tuple {
    int a, b, c;
} Tuple;
vector<Tuple> arr[MAXN];
map<int, int> kind_map;
int n, m, kind = 0, tmp[MAXN][MAXN];

int dp(int M, int idx) {
    if (~tmp[M][idx]) return tmp[M][idx];
    if (idx == 0) return tmp[M][idx] = 0;
    int ans = dp(M, idx - 1);
    for (int j = 0; j < arr[idx].size(); j++) {
        if (M >= arr[idx][j].a) ans = max(ans, dp(M - arr[idx][j].a, idx - 1) + arr[idx][j].b);
    }
    return tmp[M][idx] = ans;
}

int main() {
    kind_map.clear();
    for (int i = 0; i < MAXN; i++) arr[i].clear(), memset(tmp[i], -1, sizeof(tmp[i]));
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        Tuple tuple; tuple.a = a, tuple.b = b, tuple.c = c;
        if (kind_map.find(c) == kind_map.end()) kind_map.insert({c, ++kind});
        arr[kind_map[c]].push_back(tuple);
    }
    cout << dp(m, kind) << endl;
}
