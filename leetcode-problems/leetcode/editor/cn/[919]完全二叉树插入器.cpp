//完全二叉树 是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。 
//
// 设计一种算法，将一个新节点插入到一个完整的二叉树中，并在插入后保持其完整。 
//
// 实现 CBTInserter 类: 
//
// 
// CBTInserter(TreeNode root) 使用头节点为 root 的给定树初始化该数据结构； 
// CBTInserter.insert(int v) 向树中插入一个值为 Node.val == val的新节点 TreeNode。使树保持完全二叉树的状态
//，并返回插入节点 TreeNode 的父节点的值； 
// CBTInserter.get_root() 将返回树的头节点。 
// 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 
//
// 
//输入
//["CBTInserter", "insert", "insert", "get_root"]
//[[[1, 2]], [3], [4], []]
//输出
//[null, 1, 2, [1, 2, 3, 4]]
//
//解释
//CBTInserter cBTInserter = new CBTInserter([1, 2]);
//cBTInserter.insert(3);  // 返回 1
//cBTInserter.insert(4);  // 返回 2
//cBTInserter.get_root(); // 返回 [1, 2, 3, 4] 
//
// 
//
// 提示： 
//
// 
// 树中节点数量范围为 [1, 1000] 
// 0 <= Node.val <= 5000 
// root 是完全二叉树 
// 0 <= val <= 5000 
// 每个测试用例最多调用 insert 和 get_root 操作 10⁴ 次 
// 
// Related Topics 树 广度优先搜索 设计 二叉树 👍 127 👎 0


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
class CBTInserter {
private:
    TreeNode* node[1003];
    int sz;
    int arr[1003];
    void build_link() {
        for (int i = 0; i < sz; i++) {
            node[i]->left = (2*i+1<sz) ? node[2*i+1] : NULL;
            node[i]->right = (2*i+2 < sz) ? node[2*i+2] : NULL;
        }
    }
    void dfs(int &arr_id, int node_id) {
        if (node[node_id]->left != NULL) dfs(arr_id, 2*node_id+1);
        node[node_id]->val = arr[arr_id++];
        if (node[node_id]->right != NULL) dfs(arr_id, 2*node_id+2);
    }
public:
    CBTInserter(TreeNode* root) {
        for (int i = 0; i <= 1002; i++) node[i] = new TreeNode();
        sz = 1;
        arr[0] = root->val;
        node[0]->val = root->val;
        node[0]->left = NULL;
        node[0]->right = NULL;
    }

    int insert(int val) {
        arr[sz++] = val;
        sort(arr, arr + sz);
        build_link();
        int c = 0;
        dfs(c, 0);
        return node[0]->val;
    }

    TreeNode* get_root() {
        return node[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
//leetcode submit region end(Prohibit modification and deletion)
