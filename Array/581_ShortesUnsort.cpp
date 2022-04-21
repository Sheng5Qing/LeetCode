/*�������������*/
/*����һ���������� nums ������Ҫ�ҳ�һ�� ���������� ��
���������������������������ô�������鶼���Ϊ��������
�����ҳ���������� ��� �����飬��������ĳ��ȡ�
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�����������⣺1���ظ� 2������
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

//��������ɨ�裬��¼���ֵmaxNum,���ɨ�赽��num[i]С��maxNum����˵����λ����Ҫ��������¼λ�á���������ɨ��ͬ��
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