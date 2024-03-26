// 438. 找到字符串中所有字母异位词
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        //p比s大则不可能有异位词
        if (s.size() < p.size()) {
            return ans;
        }
        //记录p中所有字母出现的位置
        vector<int> count(26);
        for (int i = 0; i < p.size(); i++){
            count[p[i] - 'a']++;
        }
        for (int l = 0, r = 0; r < s.size(); r++) {
            count[s[r] - 'a']--;
            //新加入的字符不在窗口内，移动左边界排除多余字符，直到窗口内所有字符都在p中
            while (count[s[r] - 'a'] < 0) {
                count[s[l] - 'a']++;
                l++;
            }
            if (r - l + 1 == p.size()) {
                ans.emplace_back(l);
            }
        }
        return ans;
    }
};

struct Example{
    string s;
    string p;
    vector<int> ans;
};

int main(){
    vector<Example> examples = {
        {"cbaebabacd", "abc", {0, 6}},
        {"abab", "ab", {0, 1, 2}},
    };
    Solution* solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        vector<int> ans = solve->findAnagrams(examples[i].s, examples[i].p);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    return 0;
}

//模拟过程
// s = "cbaebabacd"
// p = "abc"
// count = [1, 1, 1, 0, 0,..., 0]
//r = 0, count[2] -= 1 = [1, 1, 0, 0, 0,..., 0]
//r - l + 1 = 1 != p.size() = 3
//r = 1, l = 0, count[1] -= 1 = [1, 0, 0, 0, 0,..., 0]
//r - l + 1 = 2 != p.size() = 3
//r = 2, l = 0, count[0] -= 1 = [0, 0, 0, 0, 0,..., 0]
//r - l + 1 = 3 == p.size() = 3
//ans = [0]
//r = 3, l = 0, count[4] -= 1 = [0, 0, 0, 0, -1,..., 0]
//while begin
//count[s[r] - 'a'] < 0 新加入的字符不在窗口内，移动左边界排除多余字符
//count[s[l] - 'a'] += 1 = [0, 0, 1, 0, -1,..., 0],l += 1 = 1
//count[s[l] - 'a'] +=1 = [0, 1, 1, 0, -1,..., 0],l += 1 = 2
//count[s[l] - 'a'] +=1 = [1, 1, 1, 0, -1,..., 0],l += 1 = 3
//count[s[l] - 'a'] +=1 = [1, 1, 1, 0, 0,..., 0],l += 1 = 4
//while end
//r = 4, l = 4, count[1] -= 1 = [1, 0, 1, 0, 0,..., 0]
//r = 5, l = 4, count[0] -= 1 = [0, 0, 1, 0, 0,..., 0]
//r = 6, l = 4, count[1] -= 1 = [0, -1, 1, 0, 0,..., 0]
//while begin
//count[s[l] - 'a'] += 1 = [0, 0, 1, 0, 0,..., 0],l += 1 = 5
//while end
//r = 7, l = 5, count[0] -= 1 = [-1, 0, 1, 0, 0,..., 0]
//while begin
//count[s[l] - 'a'] += 1 = [0, 0, 1, 0, 0,..., 0],l += 1 = 6
//while end
//r = 8, l = 6, count[2] -= 1 = [0, 0, 0, 0, 0,..., 0]
//r - l + 1 = 3 == p.size() = 3
//ans = [0, 6]
//r = 9, l = 6, count[3] -= 1 = [0, 0, 0, -1, 0,..., 0]
//while begin
//count[s[l] - 'a'] += 1 = [0, 1, 0, -1, 0,..., 0],l += 1 = 7
//count[s[l] - 'a'] += 1 = [1, 1, 0, -1, 0,..., 0],l += 1 = 8
//count[s[l] - 'a'] += 1 = [1, 1, 1, -1, 0,..., 0],l += 1 = 9
//count[s[l] - 'a'] += 1 = [1, 1, 1, 0, 0,..., 0],l += 1 = 10
//while end
//r = 10, end for



