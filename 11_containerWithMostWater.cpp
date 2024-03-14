// 11. 盛最多水的容器
// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
// 返回容器可以储存的最大水量。
// 说明：你不能倾斜容器。
// 示例 1：
// 输入：[1,8,6,2,5,4,8,3,7]
// 输出：49

// 示例 2：
// 输入：height = [1,1]
// 输出：1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            // 两边夹逼，每次移动较小的那一边
            if(height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }  
};

//构建测试脚本
int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    vector<int> height2 = {1,1};
    Solution st;
    cout << st.maxArea(height) << endl;
    cout << st.maxArea(height2) << endl;

    return 0;
}