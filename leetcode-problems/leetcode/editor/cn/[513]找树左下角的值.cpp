//给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。 
//
// 假设二叉树中至少有一个节点。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入: root = [2,1,3]
//输出: 1
// 
//
// 示例 2: 
//
// 
//
// 
//输入: [1,2,3,4,null,5,6,null,null,7]
//输出: 7
// 
//
// 
//
// 提示: 
//
// 
// 二叉树的节点个数的范围是 [1,10⁴] 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 327 👎 0


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
const int MAXN = 1e4 + 9;
vector<TreeNode*> V[MAXN];
int D;
void dfs(TreeNode *root, int deep) {
    if (root == NULL) return;
    V[deep].push_back(root);
    D = max(D, deep);
    dfs(root->left, 1 + deep);
    dfs(root->right, 1 + deep);
}

class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        for (int i = 0; i < MAXN; i++) V[i].clear();
        D = 0;
        dfs(root, 1);
        return V[D][0]->val;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
