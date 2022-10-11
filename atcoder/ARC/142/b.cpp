//
// Created by 走线大师 on 2022/6/21.
//

#include <bits/stdc++.h>
using namespace std;

int M[501][501];

signed main() {
    int N, n = 0; cin >> N;
    for (int i = 1; i <= N; i++) if (i % 2 == 1) for (int j = 1; j <= N; j++) M[i][j] = ++n;
    for (int i = 1; i <= N; i++) if (i % 2 == 0) for (int j = 1; j <= N; j++) M[i][j] = ++n;
    for (int i = 1; i <= N; i++) { for (int j = 1; j <= N; j++) cout << M[i][j] << ' '; cout << endl; }
}