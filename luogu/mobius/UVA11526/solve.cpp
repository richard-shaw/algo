//
// Created by 走线大师 on 2021/9/14.
//

#include <bits/stdc++.h>

using namespace std;
#define int long long

int H(int n) {
    int Ans = 0;
    for (int i = 1; i <= n;) {
        int j = min(n / (n / i), n);
        Ans += (j - i + 1) * (n / i);
        i = j + 1;
    }
    return Ans;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << H(n) << endl;
    }
}