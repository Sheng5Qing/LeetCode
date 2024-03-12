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