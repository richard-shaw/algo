//
// Created by 走线大师 on 2022/6/28.
//

#include <bits/stdc++.h>
using namespace std;
map<int, int> MP;
int C[10];
int main() {
    MP.clear();
    int N; cin >> N;
    for (int i = 1; i <= 9; i++) {
        cin >> C[i];
        if (MP.find(C[i]) == MP.end()) MP.insert({C[i], i});
        else MP[C[i]] = max(MP[C[i]], i);
    }
    int ls = MP.begin()->first;
    int L = N / ls;
    string ans = "";
    for (int i = 1; i <= L; i++) ans += to_string(MP.begin()->second);
    int left = N - L * ls, j = 0;
    LABEL:;
    while (left > 0 && j < L) {
        for (int i = 9; i >= 1; i--) {
            if (C[i] - ls <= left) {
                left -= C[i] - ls;
                ans[j++] = (char) (i + '0');
                goto LABEL;
            }
        }
        break;
    }
    cout << ans << endl;
}