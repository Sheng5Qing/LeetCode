#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //滑动窗口解
    int lengthOfLongestSubstring(string s) {
        // pos数组记录字符上一次出现的位置，因为是字符，所以用128大小的数组
        vector<int> pos(128, -1);
        int ans = 0;
        for (int r = 0, l = 0; r < s.size(); r++) {
            // 如果当前字符已经出现过，那么左指针移动到上一次出现的位置的下一个位置
            l = max(l, pos[s[r]] + 1);
            ans = max(ans, r - l + 1);
            // 记录当前字符的位置
            pos[s[r]] = r;
        }
        return ans;
    }
};

struct example
{
    string s;
};

int main() {
    vector<example> e = {
        {"abcabcbb"},
        {"bbbbb"},
        {"pwwkew"},
    };
    Solution solution;
    for (int i = 0; i < e.size(); i++) {
        cout << solution.lengthOfLongestSubstring(e[i].s) << endl;
    }
    return 0;
}
