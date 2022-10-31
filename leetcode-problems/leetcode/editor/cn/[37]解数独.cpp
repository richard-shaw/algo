//编写一个程序，通过填充空格来解决数独问题。 
//
// 数独的解法需 遵循如下规则： 
//
// 
// 数字 1-9 在每一行只能出现一次。 
// 数字 1-9 在每一列只能出现一次。 
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图） 
// 
//
// 数独部分空格内已填入了数字，空白格用 '.' 表示。 
//
// 
//
// 
// 
// 
// 示例 1： 
//
// 
//输入：board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".
//",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".
//","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6
//"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[
//".",".",".",".","8",".",".","7","9"]]
//输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8
//"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],[
//"4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9",
//"6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4",
//"5","2","8","6","1","7","9"]]
//解释：输入的数独如上图所示，唯一有效的解决方案如下所示：
//
//
// 
//
// 
//
// 提示： 
//
// 
// board.length == 9 
// board[i].length == 9 
// board[i][j] 是一位数字或者 '.' 
// 题目数据 保证 输入数独仅有一个解 
// 
// 
// 
// 
// Related Topics 数组 回溯 矩阵 👍 1359 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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
//leetcode submit region end(Prohibit modification and deletion)
