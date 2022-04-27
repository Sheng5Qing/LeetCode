/*移除元素*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        //快慢指针，慢指针指向需要交换的数据，快指针找用以交换的数据
        for(int fastIndex = 0; fastIndex < nums.size(); ++fastIndex){
            if(val != nums[fastIndex]){
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};