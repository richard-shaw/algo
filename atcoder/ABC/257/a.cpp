//
// Created by 走线大师 on 2022/6/28.
//

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, X;
    cin >> N >> X;
    char ans = 'A';
    while (X > N) {
        X -= N;
        ans++;
    }
    cout << ans << endl;
}