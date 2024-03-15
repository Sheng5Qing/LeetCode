//15.三数之和
//给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], 
//nums[k]] 满足 i != j、i != k 且 j != k ，
//同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
//你返回所有和为 0 且不重复的三元组
//示例 1：
//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
//示例 2：
//输入：nums = [0,1,1]
//输出：[]
//示例 3：
//输入：nums = [0,0,0]
//输出：[[0,0,0]]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//emplace_back({nums[i], nums[l], nums[r]})写法错误，应该是emplace_back(vector<int>{nums[i], nums[l], nums[r]})
//emplace_back函数的设计目的是在容器的末尾就地构造一个新元素，而不是将一个已经构造好的元素插入到容器中。
//这意味着emplace_back函数接受的参数是新元素的构造函数的参数，而不是新元素本身。
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //构建答案数组
        vector<vector<int>> ans;
        //对原数组排序
        sort(nums.begin(),nums.end());
        //将三数之和为0转换为两数之和为i
        for (int i = 0; i < nums.size(); i++) {
            //去重
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nums.size() - 1;
            int target = 0 - nums[i];
            while (l < r) {
                if (nums[l] + nums[r] == target){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    //去重
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    //双指针向中间继续寻找
                    l++;
                    r--;
                }else if (nums[l] + nums[r] < target) {
                    //小于target，则增加左指针
                    l++;
                }else {
                    r--;
                }
            }
        }
        return ans;
    }
};
struct Example {
    vector<int> nums;
    vector<vector<int>> ans;
};

int main() {
    vector<Example> examples = {
        {{-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}},
        {{0, 1, 1}, {}},
        {{0, 0, 0}, {{0, 0, 0}}}
    };
    
    Solution *solve = new Solution();
    for (int i = 0; i < examples.size(); i++) {
        vector<vector<int>> ans = solve->threeSum(examples[i].nums);
        if (ans == examples[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }
    
    return 0;
}
