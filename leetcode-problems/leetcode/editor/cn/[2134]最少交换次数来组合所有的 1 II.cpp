//交换 定义为选中一个数组中的两个 互不相同 的位置并交换二者的值。 
//
// 环形 数组是一个数组，可以认为 第一个 元素和 最后一个 元素 相邻 。 
//
// 给你一个 二进制环形 数组 nums ，返回在 任意位置 将数组中的所有 1 聚集在一起需要的最少交换次数。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [0,1,0,1,1,0,0]
//输出：1
//解释：这里列出一些能够将所有 1 聚集在一起的方案：
//[0,0,1,1,1,0,0] 交换 1 次。
//[0,1,1,1,0,0,0] 交换 1 次。
//[1,1,0,0,0,0,1] 交换 2 次（利用数组的环形特性）。
//无法在交换 0 次的情况下将数组中的所有 1 聚集在一起。
//因此，需要的最少交换次数为 1 。
// 
//
// 示例 2： 
//
// 输入：nums = [0,1,1,1,0,0,1,1,0]
//输出：2
//解释：这里列出一些能够将所有 1 聚集在一起的方案：
//[1,1,1,0,0,0,0,1,1] 交换 2 次（利用数组的环形特性）。
//[1,1,1,1,1,0,0,0,0] 交换 2 次。
//无法在交换 0 次或 1 次的情况下将数组中的所有 1 聚集在一起。
//因此，需要的最少交换次数为 2 。
// 
//
// 示例 3： 
//
// 输入：nums = [1,1,0,0,1]
//输出：0
//解释：得益于数组的环形特性，所有的 1 已经聚集在一起。
//因此，需要的最少交换次数为 0 。 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// nums[i] 为 0 或者 1 
// 
// Related Topics 数组 滑动窗口 👍 38 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
const int MAXN = 2e5 + 9;
int arr[MAXN];
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), c = 0, ans = n;
        for (int i = 0; i < n; i++) arr[i+1] = arr[i+n+1] = nums[i], c += nums[i];
        arr[0] = 0;
        for (int i = 1; i <= 2 * n; i++) arr[i] += arr[i-1];
        for (int i = 1; i <= n; i++) {
            ans = min(ans, c - arr[i+c-1] + arr[i-1]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
