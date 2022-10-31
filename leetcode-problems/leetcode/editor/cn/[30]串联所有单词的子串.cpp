//给定一个字符串 s 和一些 长度相同 的单词 words 。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。 
//
// 注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，但不需要考虑 words 中单词串联的顺序。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "barfoothefoobarman", words = ["foo","bar"]
//输出：[0,9]
//解释：
//从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
//输出的顺序不重要, [9,0] 也是有效答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
//输出：[6,9,12]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10⁴ 
// s 由小写英文字母组成 
// 1 <= words.length <= 5000 
// 1 <= words[i].length <= 30 
// words[i] 由小写英文字母组成 
// 
// Related Topics 哈希表 字符串 滑动窗口 👍 713 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans; ans.clear();
        int l = words[0].length(), N = words.size(), L = s.length();
        for (int i = 0; i < l; i++) {
            if (i + l * N > L) break;
            map<string, int> cnt; cnt.clear();
            for (int j = 0; j < N; j++) {
                string sub = s.substr(i + j * l, l);
                if (cnt.find(sub) == cnt.end()) cnt.insert({sub, 0});
                cnt[sub]++;
            }
            for (string word : words) {
                if (cnt.find(word) == cnt.end()) cnt.insert({word, -1});
                else if (cnt[word] == 1) cnt.erase(word);
                else cnt[word]--;
            }
            if (cnt.empty()) ans.push_back(i);
            int st = i, ed = i + l * N;
            while (ed + l <= L) {
                string del = s.substr(st, l), add = s.substr(ed, l);
                if (cnt.find(add) == cnt.end()) cnt.insert({add, 1});
                else cnt[add]++;
                if (cnt.find(del) == cnt.end()) cnt.insert({del, -1});
                else cnt[del]--;
                if (cnt.find(add) != cnt.end() && cnt[add] == 0) cnt.erase(add);
                if (cnt.find(del) != cnt.end() && cnt[del] == 0) cnt.erase(del);
                st += l, ed += l;
                if (cnt.empty()) ans.push_back(st);
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
