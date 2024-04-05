// 239. 滑动窗口最大值
// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
// 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
// 返回 滑动窗口中的最大值 。
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class Solution {
public:
    // 暴力解法，又超时
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i = 0; i <= nums.size() - k; ++i) {
            //注意迭代器区间为左闭右开
            ans.emplace_back(*max_element(nums.begin() + i, nums.begin() + i + k));
        }
        return ans;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
    }
};

struct Example {
    vector<int> nums;
    int k;
    vector<int> ans;
};

int main() {
    vector<Example> examples = {
        {{1,3,-1,-3,5,3,6,7}, 3, {3,3,5,5,6,7}},
        {{1}, 1, {1}},
        {{1,-1}, 1, {1, -1}},
        {{9,11}, 2, {11}},
        {{4,-2}, 2, {4}},
    };
    unique_ptr<Solution> solve {make_unique<Solution>()};
    for (int i = 0; i < examples.size(); i++) {
        vector<int> ans = solve->maxSlidingWindow1(examples[i].nums, examples[i].k);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    return 0;
}