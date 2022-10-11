//
// Created by 走线大师 on 2022/6/27.
//

#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a[3];
    for (int i = 0; i < 3; i++) cin >> a[i];
    sort(a, a+3);
    if (a[0]+a[1]-a[2]>=0) cout << a[2] << endl;
    else cout << -1 << endl;
}