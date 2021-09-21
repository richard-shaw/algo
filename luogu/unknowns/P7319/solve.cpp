//
// Created by 走线大师 on 2021/9/4.
//

#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 3;
int w[maxn], N, id[maxn];
int ex(int j) {
    return (j & 1) ? -1 : 1;
}
int kt(int i, int j) {
    int k = w[i] * ex(i), t = ex(j);
    return k * t;
}
bool cmp(int i, int j) {
    return N * (kt(i, i) + kt(j, j) - kt(i, j) - kt(j, i)) <= (i * kt(i, i) + j * kt(j, j) - j * kt(i, j) - i * kt(j, i));
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> w[i];
        id[i] = i;
    }
    sort(id, id + N, cmp);
    int Ans = 0;
    for (int i = 1; i <= N; i++) {
        int add = ex(i + w[id[i]] + 1) * w[id[i]];
        Ans += w[id[i]];
        Ans += ((N - i) * add);
    }
    cout << Ans << endl;

}