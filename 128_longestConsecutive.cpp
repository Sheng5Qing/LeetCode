// 128.最长连续序列
// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
// 示例 1：
// 输入：nums = [100,4,200,1,3,2]
// 输出：4
// 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
// 示例 2：
// 输入：nums = [0,3,7,2,5,8,4,6,0,1]
// 输出：9
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans = 0;
        for(int num: st){
            if(!st.count(num - 1)){
                int x = num + 1;
                while(st.count(x)) x++;
                ans = max(ans,x - num);
            }    
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {100,4,200,1,3,2};
    vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    Solution st;
    cout << st.longestConsecutive(nums) << endl;
    cout << st.longestConsecutive(nums2) << endl;

    return 0;
}