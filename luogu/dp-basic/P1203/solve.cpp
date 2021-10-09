//
// Created by 走线大师 on 2021/10/10.
//

#include <bits/stdc++.h>

using namespace std;
int arr[706];
inline int flag(char c) { return c == 'r' ? 1 : (c == 'b' ? 2 : 0); }
int dp(int i, int j, int c1, int c2) {
    int ans = 0, k;
    for (k = i; k <= j; k++) {
        if (arr[k] == c1 || arr[k] == 0) ans++;
        else break;
    }
    for (int k0 = j; k0 >= k; k0--) {
        if (arr[k0] == c2 || arr[k0] == 0) ans ++;
        else break;
    }
    return ans;
}
int main() {
    int N, Ans = 0;
    string s;
    cin >> N >> s;
    for (int i = 1; i <= N; i++) {
        arr[i] = arr[i + N] = flag(s[i - 1]);
    }

    for (int i = 0; i < N; i++) {
        int j = i + N - 1;
        for (int c1 = 1; c1 <= 2; c1++) for (int c2 = 1; c2 <= 2; c2++) Ans = max(Ans, dp(i + 1, j + 1, c1, c2));
    }
    cout << Ans << endl;
}