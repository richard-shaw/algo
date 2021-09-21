//
// Created by 走线大师 on 2021/9/2.
//

# include <bits/stdc++.h>

using  namespace std;
const int maxn = 1e5 + 9;
int arr[maxn], b[maxn], dp[maxn], N, L = 1;

int find_x(int x) {
    return lower_bound(b+1, b+L+1, x) - b;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    b[1] = arr[1], dp[1] = 1, L = 1;
    for (int i = 2; i <= N; i++) {
        int x = find_x(arr[i]);
        dp[i] = x;
        if (x > L) b[++L] = arr[i];
        else b[x] = min(b[x], arr[i]);
    }
    int Ans = -1;
    for (int i = 1; i <= N; i++) Ans = max(Ans, dp[i]);
    cout << N - Ans << endl;
}

