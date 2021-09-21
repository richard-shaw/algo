#include <bits/stdc++.h>

using namespace std;
int arr[7] = {0, 1, 2, 3, 3, 3, 4};
int p[6] = {1, 2, 3, 4, 5, 6};
int main() {
    int Ans = 0;
    do {
        int aq[7], bq[7];
        for (int i = 1; i <= 6; i++) aq[i] = bq[i] = arr[p[i-1]];

        int last = 0;
        while(true) {
            bool ok = false;
            for (int i = 1; i <= 6; i++) {
                if (aq[i] == 1) ok = true;
            }
            if (!ok) break;
            for (int i = 1; i <= 6; i++) {
                if (aq[i] == 0) continue;
                if (last == i) goto SK;
                last = i;
                aq[i]--;
            }
        }

        Ans++;
        continue;
        SK:;
        for (int i = 1; i <= 6; i++) cout << bq[i] << ' ';
        cout << endl;
    } while(next_permutation(p, p + 6));
    cout << Ans << endl;
}