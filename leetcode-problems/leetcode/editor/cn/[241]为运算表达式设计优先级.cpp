//给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。 
//
// 生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 10⁴ 。 
//
// 
//
// 示例 1： 
//
// 
//输入：expression = "2-1-1"
//输出：[0,2]
//解释：
//((2-1)-1) = 0 
//(2-(1-1)) = 2
// 
//
// 示例 2： 
//
// 
//输入：expression = "2*3-4*5"
//输出：[-34,-14,-10,-10,10]
//解释：
//(2*(3-(4*5))) = -34 
//((2*3)-(4*5)) = -14 
//((2*(3-4))*5) = -10 
//(2*((3-4)*5)) = -10 
//(((2*3)-4)*5) = 10
// 
//
// 
//
// 提示： 
//
// 
// 1 <= expression.length <= 20 
// expression 由数字和算符 '+'、'-' 和 '*' 组成。 
// 输入表达式中的所有整数值在范围 [0, 99] 
// 
// Related Topics 递归 记忆化搜索 数学 字符串 动态规划 👍 667 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
bool all_number(string s) {
    for (char ch : s) if (ch == '+' || ch == '-' || ch == '*') return false;
    return true;
}
vector<int> dfs(string expression) {
    if (all_number(expression)) { vector<int> ans; ans.push_back(atoi(expression.c_str())); return ans; }
    vector<int> ans; ans.clear();
    int n = expression.length();
    for (int i = 0; i < n; i++) {
        if (expression[i] >= '0' && expression[i] <= '9') continue;
        vector<int> L = dfs(expression.substr(0, i)), R = dfs(expression.substr(i+1, n-1-i));
        for (int l : L) for (int r : R) {
                if (expression[i] == '+') ans.push_back(l + r);
                else if (expression[i] == '-') ans.push_back(l - r);
                else if (expression[i] == '*') ans.push_back(l * r);
            }
    }
    return ans;

}

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
