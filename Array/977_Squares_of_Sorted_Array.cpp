/*有序数组的平方*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    //非递减，大头在两边
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret(nums.size(),0);
        int l = 0, r = nums.size() - 1;
        int index = nums.size() - 1;
        while (l <= r) {
            if(pow(nums[l],2) > pow(nums[r],2)){
                ret[index--] = pow(nums[l++],2);
            }else {
                ret[index--] = pow(nums[r--],2);
            }
        }
        return ret;
    }
};