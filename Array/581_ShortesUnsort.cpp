/*最短无序子数组*/
/*给你一个整数数组 nums ，你需要找出一个 连续子数组 ，
如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
请你找出符合题意的 最短 子数组，并输出它的长度。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//忽略两个问题：1、重复 2、连续
int findUnsortedSubarray1(vector<int>& nums) {
    vector<int> temp(nums);
    sort(nums.begin(),nums.end());
    int count = 0;
    int i = 0;
    for(auto c:nums){
        if(c != temp[i++]){
            count++;
        }
    }
    return count;
}

//从左往右扫描，记录最大值maxNum,如果扫描到的num[i]小于maxNum，则说明该位置需要调整，记录位置。从右往左扫描同理
int findUnsortedSubarray(vector<int>& nums){
    int len = nums.size();
    if(len <= 1)
        return 0;
    int low = 0,high = len - 1, maxNum = nums[low],minNum = nums[high];
    for(int i = 1; i < len; i++){
        maxNum = max(maxNum, nums[i]);
        if(maxNum > nums[i]) low = i;
        minNum = min(minNum, nums[len - i - 1]);
        if(minNum < nums[len - i - 1]) high = len - i - 1;
    }
    return low > high ? low - high + 1 : 0;
}

int main(){
    vector<int> nums = {2,6,4,8,10,9,15};
    cout << findUnsortedSubarray(nums);
    return 0;
}