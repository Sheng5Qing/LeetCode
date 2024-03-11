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

