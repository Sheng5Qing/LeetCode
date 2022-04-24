/*�������������*/
/*����һ��δ��������������飬�ҵ���� ���������������У������ظ����еĳ��ȡ�
���������������� �����������±� l �� r��l < r��ȷ����
�������ÿ�� l <= i < r������ nums[i] < nums[i + 1] ��
��ô������ [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] �����������������С�
*/
#include <iostream>
#include <vector>

using namespace std;

int findLengthOfLCIS(vector<int>& nums) {
    //��¼�����п�ʼ����
    int l = 0;
    //�����г���
    int cnt = 1;
    int cntMax = 1;
    while (l != nums.size() - 1) {
        if(nums[l] < nums[l + 1]){
            ++cnt;
            if(cnt > cntMax){
                cntMax = cnt;
            }
        }else {
            cnt = 1;
        }
        ++l;
    }
    return cntMax;
}

int main(){

    return 0;
}