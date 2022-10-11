//
// Created by 走线大师 on 2022/6/28.
//

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 9;
bitset<MAXN> R, J;
map<int, vector<int>> MP;
int main() {
    MP.clear();
    int N; cin >> N;
    string buf; cin >> buf;
    R.reset(); J.reset();
    for (int i = 0; i < N; i++) {
        J.set(i);
        if (buf[i] == '1') R.set(i);
    }
    int ans = N - (R ^ J).count(), tmp = ans;
    for (int i = 0; i < N; i++) {
        int W; cin >> W;
        if (MP.find(W) == MP.end()) {
            vector<int> v;
            v.clear();
            MP.insert({W, v});
        }
        MP[W].push_back(i);
    }


    for (auto ite = MP.begin(); ite != MP.end(); ++ite) {
        for (int idx : ite->second) {
            J.reset(idx);
            if (R[idx] == J[idx]) tmp++;
            else tmp--;
        }
        ans = max(ans, tmp);
    }

    cout << ans;
}