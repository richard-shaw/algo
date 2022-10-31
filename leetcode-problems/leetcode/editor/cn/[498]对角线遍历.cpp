//给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。 
//
// 
//
// 示例 1： 
//
// 
//输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,4,7,5,3,6,8,9]
// 
//
// 示例 2： 
//
// 
//输入：mat = [[1,2],[3,4]]
//输出：[1,2,3,4]
// 
//
// 
//
// 提示： 
//
// 
// m == mat.length 
// n == mat[i].length 
// 1 <= m, n <= 10⁴ 
// 1 <= m * n <= 10⁴ 
// -10⁵ <= mat[i][j] <= 10⁵ 
// 
// Related Topics 数组 矩阵 模拟 👍 370 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
const int MAXN = 1e4 + 10;
struct Elem {
    int i, j, e;
    void set(int _i, int _j, int _e) { i = _i, j = _j, e = _e; }
} elem[MAXN];
bool cmp(Elem &a, Elem &b) {
    if (a.i + a.j < b.i + b.j) return true;
    else if (a.i + a.j > b.i + b.j) return false;
    int f = (a.i + a.j) % 2;
    if (f == 0) return a.j < b.j;
    else return a.i < b.i;
}
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) elem[cnt++].set(i, j, mat[i][j]);
        sort(elem, elem + cnt, cmp);
        vector<int> ans(cnt);
        for (int i = 0; i < cnt; i++) ans[i] = elem[i].e;
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
