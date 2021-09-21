//
// Created by 走线大师 on 2021/9/14.
//

#include <bits/stdc++.h>
#define int long long
using namespace std;
int G(int n, int k) {
    int Ans = n * k;
    for (int i = 1; i <= min(n, k);) {
        int j = min(k / (k / i), min(n, k));
        Ans -= (k / i) * (i + j) * (j - i + 1) / 2;
        i = j + 1;
    }
    return Ans;
}

signed main() {
    int n, k;
    cin >> n >> k;
    cout << G(n, k) << endl;
}