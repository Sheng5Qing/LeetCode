/*三个数的最大乘积*/
/*给你一个整型数组 nums ，在数组中找出由三个数组成的最大乘积，并输出这个乘积。*/
#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maximumProduct2(vector<int>& nums) {
    sort(nums.begin(),nums.end(),greater<int>());
    return nums[0] * nums[1] * nums[2];
}
/*错了，是三个数组成的最大乘积，不是三个最大数的乘积*/

int maximumProduct(vector<int>& nums) {
    sort(nums.begin(),nums.end(),greater<int>());
    int a = nums[0] * nums[1] * nums[2];
    int b = (*(nums.end() - 1)) * (*(nums.end() - 2)) * nums[0];
    return a > b ? a : b;
}

int main(){
    vector<int> x{-100,-98,-1,2,3,4};
    cout << maximumProduct(x) << endl;
    return 0;
}