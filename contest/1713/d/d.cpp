#include <bits/stdc++.h>
#define pb(x) push_back(x)
using namespace std;
int win[10];
int omg(int i, int q, int lw) {
    cout << "? " << win[i] << ' ' << q << endl;
    cout.flush();
    int k; cin >> k;    cout.flush();
    return k <= 1 ? lw : q;
}

int dp(int n) {
    if (n == 1) return 1;
    if (n == 2 || n == 4 || n == 8 || n == 16) {
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            cout << "? " << ans << ' ' << i << endl;
            cout.flush();
            int k; cin >> k;    cout.flush();
            if (k == 2) ans = i;
        }
        return ans;
    }
    int base2;
    if (n == 3) base2 = 2;
    else if (n < 8) base2 = 4;
    else if (n < 16) base2 = 8;
    else base2 = 16;
    int q = dp(n - base2) + base2;

    vector<int> player; player.clear();
    for (int i = 1; i <= base2; i++) player.pb(i);
    int w = 0;
    while (player.size() > 1) {
        vector<int> nxt; nxt.clear();
        for (int i = 0; i < player.size()-1; i+=2) {
            cout << "? " << player[i] << ' ' << player[i+1] << endl;
            cout.flush();
            int k; cin >> k;    cout.flush();
            if (k == 1) win[w] = player[i+1], nxt.pb(player[i]);
            else win[w] = player[i], nxt.pb(player[i+1]);
        }
        w++;
        player = nxt;
    }
    win[w] = player[0];
    int xx = player[0];
    if (n == 3) {
        return omg(1, q, xx);
    } else if (n == 5) {
        return omg(1, q, xx);
    } else if (n == 6) {
        return omg(2, q, xx);
    } else if (n == 7) {
        if (q <= 6) return omg(3, q, xx);
        return omg(2, q, xx);
    } else if (n == 9) {
        return omg(1, q, xx);
    } else if (n == 10) {
        return omg(2, q, xx);
    } else if (n == 11) {
        if (q <= 10) return omg(3, q, xx);
        return omg(2, q, xx);
    } else if (n == 12) {
        return omg(3, q, xx);
    } else if (n == 13) {
        if (q <= 12) return omg(4, q, xx);
        return omg(2, q, xx);
    } else if (n == 14) {
        if (q <= 12) return omg(4, q, xx);
        return omg(3, q, xx);
    } else if (n == 15) {
        if (q <= 14) return omg(4, q, xx);
        return omg(3, q, xx);
    } else if (n == 17) {
        return omg(1, q, xx);
    }

}

void solve() {
    /** Code here for each Case */
    int n;
    cin >> n;
    cout.flush();
    if (n == 1) { cout << "! 1" << endl; cout.flush(); return; }
    else if (n == 2) {
        cout << "? 1 2" << endl;
        cout.flush();
        int k; cin >> k;    cout.flush();
        cout << "! " << (k == 1 ? 1 : 2) << endl;
        cout.flush();
    }
    else if (n == 4 || n == 8 || n == 16){
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            cout << "? " << ans << ' ' << i << endl;
            cout.flush();
            int k; cin >> k;    cout.flush();
            if (k == 2) ans = i;
        }
        cout << "! " << ans << endl;
        cout.flush();
    }
    else {
        int x = dp(n);
        cout << "! " << x << endl;
        cout.flush();
    }
}

int main() {
    int t;
    cin >> t;
    cout.flush();
    while (t--) solve();
}