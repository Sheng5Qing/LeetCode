// 560. 和为 K 的子数组
// 提示
// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
// 子数组是数组中元素的连续非空序列。
// 示例 1：
// 输入：nums = [1,1,1], k = 2
// 输出：2
// 示例 2：
// 输入：nums = [1,2,3], k = 3
// 输出：2
# include <iostream>
# include <vector>
# include <unordered_map>
# include <memory>

using namespace std;

class Solution {
public:
    // 暴力解法，超时
    int subarraySum1(vector<int>& nums, int k) {
        int ans = 0;
        int tmp = 0;
        for(int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for(int j = i; j <nums.size();j++) {
                sum += nums[j];
                if(sum == k) {
                    ++ans;
                }
            }
       }
       return ans; 
    }
    // 哈希+前缀和 时间复杂度O(n) 空间复杂度O(n)
    // 将问题转化为寻找和为k的子数组，而不是直接在数组中寻找和为k的连续元素,这样就可以使问题在一次遍历中解决
    // 具体来说就是：对于每个前缀和，都检查是否存在一个早先的前缀和，使得它们的差等于k。如果存在，我们就找到了一个和为k的子数组。
    int subarraySum2(vector<int>& nums, int k) {
        int preSum = 0;  // 前缀和
        int ans = 0; 
        unordered_map<int, int> record; // 键：前缀和， 值：前缀和出现的次数
        record[0] = 1;       // 前缀和为0出现的次数为1，此时为空区间
        for(const int &num : nums){
            preSum += num;  // 遍历到当前数字的前缀和preSum
            if(record.count(preSum - k)){   // 检查当前的前缀和preSum减去目标值k后的结果是否在哈希表mp中存在
                ans += record[preSum - k];  // 有几个区间前缀和等于preSum-k，答案就加上几
            }
            record[preSum] ++;    // 前缀和为preSum的区间个数+1
        }
        
        return ans;
    }
};

struct Example{
    vector<int> nums;
    int k;
    int ans;
};

int main() {
    vector<Example> example = {
        {{1, -1, 0}, 0, 3},
        {{1, 1, 1}, 2, 2},
        {{1, 2, 3}, 3, 2},
    };

    //Solution* solve = new Solution();
    unique_ptr<Solution> solve = make_unique<Solution>();
    for(int i = 0; i < example.size(); i++) {
        int ans = solve->subarraySum2(example[i].nums, example[i].k);
        if(ans == example[i].ans) {
            cout << "PASS: CASE " << i << endl;
        } else {
            cout << "FAIL: CASE " << i << endl;
        }
    }

    return 0;
}