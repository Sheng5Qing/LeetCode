/*子数组的最大平均数*/
/*给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。
请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。
任何误差小于 10-5 的答案都将被视为正确答案。
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

//试试暴力解会不会超时
double findMaxAverage2(vector<int>& nums, int k) {
    vector<double> a;
    double avg;
    int i = 0;
    while (i + k <= nums.size()) {
        int sum = accumulate(nums.begin() + i,nums.begin() + i + k,0);
        avg = static_cast<double>(sum) / k;
        a.push_back(avg);
        ++i;
    }   
    sort(a.begin(),a.end(),greater<double>());
    return a[0];
}
/*果然超时了*/
/*滑动窗口*/
double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.begin() + k, 0);
    int tmpMax = sum;
    for(int i = 1; i + k - 1 < n; ++i){
        sum += nums[i + k - 1] - nums[i - 1];
        tmpMax = max(sum, tmpMax);
    }
    return static_cast<double>(tmpMax) / k;
}


int main(){
    return 0;
}
