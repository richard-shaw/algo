//
// Created by 走线大师 on 2021/8/23.
//

#include <bits/stdc++.h>
using namespace std;
int arr[22];
bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}
int n, k, total = 0;
void dfs(int i, int k9, int sum) {
    if (i > n) {
        if (k9 == k) {
            total += is_prime(sum);
        }
        return;
    }
    dfs(i + 1, k9, sum);
    dfs(i + 1, k9 + 1, sum + arr[i]);
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    dfs(1, 0, 0);
    cout << total << endl;
}