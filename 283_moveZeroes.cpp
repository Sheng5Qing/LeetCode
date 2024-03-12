// 283.移动零
// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
// 示例 1：
// 输入：nums = [0,1,0,3,12]
// 输出：[1,3,12,0,0]
// 示例 2：
// 输入：nums = [0]
// 输出：[0]
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j]) nums[index++] = nums[j];
        }
        while(index < nums.size()) nums[index++] = 0;
    }
};

int main() {
    vector<int> nums = {0,1,0,3,12};
    Solution st;
    st.moveZeroes(nums);
    for (auto &num: nums){
        cout << num << " ";
    }
    
    return 0;
}