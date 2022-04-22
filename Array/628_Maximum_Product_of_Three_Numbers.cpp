/*�����������˻�*/
/*����һ���������� nums �����������ҳ�����������ɵ����˻������������˻���*/
#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maximumProduct2(vector<int>& nums) {
    sort(nums.begin(),nums.end(),greater<int>());
    return nums[0] * nums[1] * nums[2];
}
/*���ˣ�����������ɵ����˻�����������������ĳ˻�*/

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