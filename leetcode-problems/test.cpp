#include <bits/stdc++.h>

using namespace std;
#define LL long long
const int MAXN = 2e5 + 9;


class Solution {
private:
    bitset<9> row[9], col[9], cell[9];
    pair<int, int> next_point(int i, int j) {
        j ++;
        if (j == 9) i ++, j = 0;
        if (i == 9) return {-1, -1};
        return {i, j};
    }
    void dfs(vector<vector<char>> &board, int i, int j, bool &ok) {
        if (ok) return;
        if (i == -1) { ok = true; return; }
        pair<int, int> nx = next_point(i, j);
        if (board[i][j] <= '9' && board[i][j] >= '1') {
            dfs(board, nx.first, nx.second, ok);
        } else {
            for (int d = 0; d < 9; d++) {
                int c = (i/3) * 3 + (j/3);
                if (row[i][d] == 0 && col[j][d] == 0 && cell[c][d] == 0) {
                    row[i].set(d), col[j].set(d), cell[c].set(d);
                    board[i][j] = '1' + d;
                    dfs(board, nx.first, nx.second, ok);
                    if (ok) return;
                    row[i].reset(d), col[j].reset(d), cell[c].reset(d);
                    board[i][j] = ' ';
                }
            }
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) row[i].reset(), col[i].reset(), cell[i].reset();
        for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) {
            if (board[i][j] <= '9' && board[i][j] >= '1') {
                int k = board[i][j]-'0'-1;
                row[i].set(k);
                col[j].set(k);
                cell[(i/3)*3+(j/3)].set(k);
            }
        }
        bool ok = false;
        dfs(board, 0, 0, ok);
    }
};

int main() {
    vector<vector<char>> v; v.clear();
    for (int i = 0; i < 9; i++) {
        vector<char> v0; v0.clear();
        for (int j = 0; j < 9; j++) v0.push_back(' ');
        v.push_back(v0);
    }
    Solution S;
    S.solveSudoku(v);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}