// 49.字母异味词分组
// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
// 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。
// 示例 1:
// 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
// 示例 2:
// 输入: strs = [""]
// 输出: [[""]]
// 示例 3:
// 输入: strs = ["a"]
// 输出: [["a"]]
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> record;
        for (string& str: strs) {
            string key = str;
            sort(key.begin(),key.end());
            record[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = record.begin(); it != record.end(); it++) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

void test1() {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = solution.groupAnagrams(strs);
    for (const auto& group : ans) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }
}

struct Example {
    vector<string> strs;
    vector<vector<string>> ans;
};

void test2(){
    vector<Example> examples = {
        {{"eat", "tea", "tan", "ate", "nat", "bat"}, {{"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}}},
        {{""},{{""}}},
        {{"a"},{{"a"}}}
    };
    
    Solution* solution = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        vector<vector<string>> ans = solution->groupAnagrams(examples[i].strs);
        sort(ans.begin(), ans.end());
        sort(examples[i].ans.begin(), examples[i].ans.end());
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
}

int main() {
    //test1();
    test2();
    return 0;
}

