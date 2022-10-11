//
// Created by 走线大师 on 2022/6/28.
//

#include <bits/stdc++.h>
using namespace std;
int A[202];
int main() {
    int N, K, Q; cin >> N >> K >> Q;
    for (int i = 1; i <= K; i++) cin >> A[i];
    while (Q--) {
        int L; cin >> L;
        if (L == K) {
            if (A[L] == N) continue;
            else A[L]++;
        } else {
            if (A[L] + 1 == A[L+1]) continue;
            else A[L]++;
        }
    }
    for (int i = 1; i <= K; i++) cout << A[i] << ' ';
    cout << endl;
}