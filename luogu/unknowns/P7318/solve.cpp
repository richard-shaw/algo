//
// Created by 走线大师 on 2021/9/4.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;

int J[2][10][10][2] = {
        {
            {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}},
            {{0, 0}, {1, 1}, {8, 2}, {7, 3}, {4, 4}, {5, 5}, {6, 6}, {3, 7}, {2, 8}, {9, 9}},
            {{0, 0}, {4, 8}, {2, 6}, {8, 4}, {6, 2}, {0, 0}, {4, 8}, {2, 6}, {8, 4}, {6, 2}},
            {{0, 0}, {9, 7}, {2, 4}, {3, 1}, {6, 8}, {5, 5}, {4, 2}, {7, 9}, {8, 6}, {1, 3}},
            {{0, 0}, {6, 4}, {8, 8}, {2, 2}, {4, 6}, {0, 0}, {6, 4}, {8, 8}, {2, 2}, {4, 6}},
            {{0, 0}, {5, 5}, {0, 0}, {5, 5}, {0, 0}, {5, 5}, {0, 0}, {5, 5}, {0, 0}, {5, 5}},
            {{0, 0}, {6, 6}, {8, 2}, {2, 8}, {4, 4}, {0, 0}, {6, 6}, {8, 2}, {2, 8}, {4, 4}},
            {{0, 0}, {9, 3}, {2, 6}, {3, 9}, {6, 2}, {5, 5}, {4, 8}, {7, 1}, {8, 4}, {1, 7}},
            {{0, 0}, {4, 2}, {2, 4}, {8, 6}, {6, 8}, {0, 0}, {4, 2}, {2, 4}, {8, 6}, {6, 8}},
            {{0, 0}, {1, 9}, {8, 8}, {7, 7}, {4, 6}, {5, 5}, {6, 4}, {3, 3}, {2, 2}, {9, 1}}
        },
        {
            {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}},
            {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {8, 8}, {9, 9}},
            {{0, 0}, {1, 2}, {2, 4}, {3, 6}, {4, 8}, {5, 0}, {6, 2}, {7, 4}, {8, 6}, {9, 8}},
            {{0, 0}, {1, 3}, {2, 6}, {3, 9}, {4, 2}, {5, 5}, {6, 8}, {7, 1}, {8, 4}, {9, 7}},
            {{0, 0}, {1, 4}, {2, 8}, {3, 2}, {4, 6}, {5, 0}, {6, 4}, {7, 8}, {8, 2}, {9, 6}},
            {{0, 0}, {1, 5}, {2, 0}, {3, 5}, {4, 0}, {5, 5}, {6, 0}, {7, 5}, {8, 0}, {9, 5}},
            {{0, 0}, {1, 6}, {2, 2}, {3, 8}, {4, 4}, {5, 0}, {6, 6}, {7, 2}, {8, 8}, {9, 4}},
            {{0, 0}, {1, 7}, {2, 4}, {3, 1}, {4, 8}, {5, 5}, {6, 2}, {7, 9}, {8, 6}, {9, 3}},
            {{0, 0}, {1, 8}, {2, 6}, {3, 4}, {4, 2}, {5, 0}, {6, 8}, {7, 6}, {8, 4}, {9, 2}},
            {{0, 0}, {1, 9}, {2, 8}, {3, 7}, {4, 6}, {5, 5}, {6, 4}, {7, 3}, {8, 2}, {9, 1}}
        }
};

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    if (k == 1) cout << n << endl;
    else if (k == 2) cout << m << endl;
    else {
        k -= 2;
        while(k > N) {
            int tn = J[0][n][m][0], tm = J[0][n][m][1];
            n = tn, m = tm;
            k -= N;
        }
        while(k--) {
            int tn = J[1][n][m][0], tm = J[1][n][m][1];
            n = tn, m = tm;
        }
        cout << m << endl;
    }
}