//给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。 
//
// 一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: root = [5,2,-3]
//输出: [2,-3,4]
// 
//
// 示例 2： 
//
// 
//
// 
//输入: root = [5,2,-5]
//输出: [2]
// 
//
// 
//
// 提示: 
//
// 
// 节点数在 [1, 10⁴] 范围内 
// -10⁵ <= Node.val <= 10⁵ 
// 
// Related Topics 树 深度优先搜索 哈希表 二叉树 👍 169 👎 0


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

map<int, int> MP;
int dfs(TreeNode *root) {
    if (root == NULL) return 0;
    int tot = root->val + dfs(root->left) + dfs(root->right);
    if (MP.find(tot) == MP.end()) MP[tot] = 0;
    MP[tot]++;
    return tot;
}
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        MP.clear();
        dfs(root);
        int m = 0;
        for (auto ite = MP.begin(); ite != MP.end(); ++ite) m = max(m, ite->second);
        vector<int> Q;
        Q.clear();
        for (auto ite = MP.begin(); ite != MP.end(); ++ite) if (ite->second == m) Q.push_back(ite->first);
        return Q;
    }
};//leetcode submit region end(Prohibit modification and deletion)
