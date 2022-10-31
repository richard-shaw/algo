//给定一个字符串数组 arr，字符串 s 是将 arr 的含有 不同字母 的 子序列 字符串 连接 所得的字符串。 
//
// 请返回所有可行解 s 中最长长度。 
//
// 子序列 是一种可以从另一个数组派生而来的数组，通过删除某些元素或不删除元素而不改变其余元素的顺序。 
//
// 
//
// 示例 1： 
//
// 
//输入：arr = ["un","iq","ue"]
//输出：4
//解释：所有可能的串联组合是：
//- ""
//- "un"
//- "iq"
//- "ue"
//- "uniq" ("un" + "iq")
//- "ique" ("iq" + "ue")
//最大长度为 4。
// 
//
// 示例 2： 
//
// 
//输入：arr = ["cha","r","act","ers"]
//输出：6
//解释：可能的解答有 "chaers" 和 "acters"。
// 
//
// 示例 3： 
//
// 
//输入：arr = ["abcdefghijklmnopqrstuvwxyz"]
//输出：26
// 
//
// 
//
// 提示： 
//
// 
// 1 <= arr.length <= 16 
// 1 <= arr[i].length <= 26 
// arr[i] 中只含有小写英文字母 
// 
// Related Topics 位运算 数组 字符串 回溯 👍 205 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    void dfs(int i, int n, bitset<26> status, int cur, int &ans, vector<bitset<26>> &bs) {
        if (i == n) ans = max(ans, cur);
        else {
            dfs(i+1, n, status, cur, ans, bs);
            if ((status & bs[i]).count() == 0) dfs(i+1, n, status | bs[i], cur + bs[i].count(), ans, bs);
        }
    }
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> bs; bs.clear();
        for (string buf : arr) {
            bitset<26> status; status.reset();
            bool ok = true;
            for (char ch : buf) {
                if (status[ch-'a']) { ok = false; break; }
                else status.set(ch-'a');
            }
            if (ok) bs.push_back(status);
        }
        int n = bs.size(), ans = 0;
        if (n == 0) return 0;

        bitset<26> start; start.reset();
        dfs(0, n, start, 0, ans, bs);
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
