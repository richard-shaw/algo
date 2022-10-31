//给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。 
//
// 
//
// 示例1： 
//
// 
//
// 
//输入: root = [1,3,2,5,3,null,9]
//输出: [1,3,9]
// 
//
// 示例2： 
//
// 
//输入: root = [1,2,3]
//输出: [1,3]
// 
//
// 
//
// 提示： 
//
// 
// 二叉树的节点个数的范围是 [0,10⁴] 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
//
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 217 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
const int MAXN = 1e4 + 10;
int Q[MAXN], D;
void dfs(TreeNode *node, int deep) {
    if (node == NULL) return;
    Q[deep] = max(Q[deep], node->val);
    D = max(D, deep);
    dfs(node->left, deep + 1);
    dfs(node->right, deep + 1);

}
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        D = 1;
        vector<int> ans; ans.clear();
        if (root == NULL) return ans;
        for (int i = 0; i < MAXN; i++) Q[i] = (1 << 31);
        dfs(root, 1);
        for (int i = 1; i <= D; i++) ans.push_back(Q[i]);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
