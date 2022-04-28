#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0;    // 滑动窗口数值之和
        int beg = 0;  // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            // 注意这里使用while，每次更新 i（起始位置），并不断缩小窗口，比较子序列是否符合条件
            while (sum >= target) {
                subLength = (i - beg + 1);    // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[beg++];   // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};
