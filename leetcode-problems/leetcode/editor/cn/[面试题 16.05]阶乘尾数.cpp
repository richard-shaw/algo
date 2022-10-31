//设计一个算法，算出 n 阶乘有多少个尾随零。 
//
// 示例 1: 
//
// 输入: 3
//输出: 0
//解释: 3! = 6, 尾数中没有零。 
//
// 示例 2: 
//
// 输入: 5
//输出: 1
//解释: 5! = 120, 尾数中有 1 个零. 
//
// 说明: 你算法的时间复杂度应为 O(log n) 。 
// Related Topics 数学 👍 76 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        long long fb = 5;
        while (n >= fb) {
            ans += (n / fb);
            fb *= 5;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
