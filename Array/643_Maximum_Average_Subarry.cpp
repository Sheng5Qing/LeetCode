/*����������ƽ����*/
/*����һ���� n ��Ԫ����ɵ��������� nums ��һ������ k ��
�����ҳ�ƽ��������� ����Ϊ k �����������飬����������ƽ������
�κ����С�� 10-5 �Ĵ𰸶�������Ϊ��ȷ�𰸡�
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

//���Ա�����᲻�ᳬʱ
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
/*��Ȼ��ʱ��*/
/*��������*/
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
