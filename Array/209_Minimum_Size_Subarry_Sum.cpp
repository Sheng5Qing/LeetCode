#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0;    // ����������ֵ֮��
        int beg = 0;  // ����������ʼλ��
        int subLength = 0; // �������ڵĳ���
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            // ע������ʹ��while��ÿ�θ��� i����ʼλ�ã�����������С���ڣ��Ƚ��������Ƿ��������
            while (sum >= target) {
                subLength = (i - beg + 1);    // ȡ�����еĳ���
                result = result < subLength ? result : subLength;
                sum -= nums[beg++];   // �������ֳ��������ڵľ���֮�������ϱ��i�������е���ʼλ�ã�
            }
        }
        // ���resultû�б���ֵ�Ļ����ͷ���0��˵��û�з���������������
        return result == INT32_MAX ? 0 : result;
    }
};
