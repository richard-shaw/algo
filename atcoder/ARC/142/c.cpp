//
// Created by 走线大师 on 2022/6/21.
//

#include <bits/stdc++.h>
using namespace std;
int D[2][101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    for (int k = 0; k < 2; k++) for (int i = 3; i <= N; i++) {
        cout << "? " << (k+1) << " " << i << endl;
        cin >> D[k][i];
    }
    int mn = D[0][3] + D[1][3];
    for (int i = 3; i <= N; i++) mn = min(mn, D[0][i] + D[1][i]);

    if (mn > 3) cout << "! " << mn << endl;
    else {
        vector<int> D2; D2.clear();
        for (int i = 3; i <= N; i++) if (D[0][i] + D[1][i] == 3) D2.push_back(i);
        if (D2.size() != 2) cout << "! 1" << endl;
        else {
            int x = D2[0], y = D2[1], t;
            cout << "? " << x << ' ' << y << endl;
            cin >> t;
            if (t == 1) cout << "! 3" << endl;
            else cout << "! 1" << endl;
        }
    }
}