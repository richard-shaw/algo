//设计一个包含一些单词的特殊词典，并能够通过前缀和后缀来检索单词。 
//
// 实现 WordFilter 类： 
//
// 
// WordFilter(string[] words) 使用词典中的单词 words 初始化对象。 
// f(string pref, string suff) 返回词典中具有前缀 prefix 和后缀 suff 的单词的下标。如果存在不止一个满足要求的下标，
//返回其中 最大的下标 。如果不存在这样的单词，返回 -1 。 
// 
//
// 
//
// 示例： 
//
// 
//输入
//["WordFilter", "f"]
//[[["apple"]], ["a", "e"]]
//输出
//[null, 0]
//解释
//WordFilter wordFilter = new WordFilter(["apple"]);
//wordFilter.f("a", "e"); // 返回 0 ，因为下标为 0 的单词：前缀 prefix = "a" 且 后缀 suff = "e" 。
//
// 
// 
//
// 提示： 
//
// 
// 1 <= words.length <= 10⁴ 
// 1 <= words[i].length <= 7 
// 1 <= pref.length, suff.length <= 7 
// words[i]、pref 和 suff 仅由小写英文字母组成 
// 最多对函数 f 执行 10⁴ 次调用 
// 
// Related Topics 设计 字典树 字符串 👍 149 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class WordFilter {
private:
    map<string, set<int>> p, s;
    map<pair<string, string>, int> ans;
    void pt(map<string, set<int>> &mp, string buf, int idx) {
        ans.clear();
        if (mp.find(buf) == mp.end()) {
            set<int> ss; ss.clear(); ss.insert(idx);
            mp.insert({buf, ss});
        }
        else mp[buf].insert(idx);
    }
public:
    WordFilter(vector<string>& words) {
        p.clear();
        s.clear();
        int n = words.size();
        for (int idx = 0; idx < n; idx++) {
            string word = words[idx];
            int l = word.length();
            for (int i = 1; i <= l; i++) pt(p, word.substr(0, i), idx);
            for (int i = 1; i <= l; i++) pt(s, word.substr(l-i, i), idx);
        }
    }

    int f(string pref, string suff) {
        if (ans.find({pref, suff}) != ans.end()) return ans[{pref, suff}];
        if (p.find(pref) == p.end() || s.find(suff) == s.end()) return -1;
        set<int> ps = p[pref], ss = s[suff];
        for (auto ite = ps.end(); ite != ps.begin(); --ite) {
            int idx = *prev(ite);
            if (ss.find(idx) != ss.end()) {
                ans.insert({{pref, suff}, idx});
                return idx;
            }
        }
        ans.insert({{pref, suff}, -1});
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
//leetcode submit region end(Prohibit modification and deletion)
