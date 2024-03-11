/*数组的度*/
/*给定一个非空且只包含非负数的整数数组nums，
数组的度的定义是指数组里任一元素出现频数的最大值。
你的任务是在 nums 中找到与?nums?拥有相同大小的度的最短连续子数组，返回其长度。*/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//究极暴力解法 超时
class degree {
public:
    int number;
    int deg = 0;
    int begin;
    int end;
};
int findShortestSubArray(vector<int>& nums) {
    degree d[50000];
    int d_len = 0;
    for (int j = 0; j != nums.size(); ++j) {
        if (d_len == 0) {
            d[0].number = nums[j];
            ++d[0].deg;
            d[0].begin = 0;
            d[0].end = 0;
            ++d_len;
            continue;
        }
        for (int i = 0; i != d_len; ++i) {
            if (nums[j] == d[i].number) {
                ++d[i].deg;
                d[i].end = j;
            }
        }
        d[d_len].number = nums[j];
        ++d[d_len].deg;
        d[d_len].begin = j;
        d[d_len].end = j;
        ++d_len;
    }
    int cnt = 1;
    for (int i = 0; i != d_len; ++i) {
        if (d[i].deg >= cnt) {
            cnt = d[i].deg;
        }
    }
    int len = 50000;
    for (int i = 0; i != d_len; ++i) {
        if (d[i].deg == cnt) {
            if ((d[i].end - d[i].begin + 1) < len) {
                len = d[i].end - d[i].begin + 1;
            }
        }
    }
    return len;
}

int main() {
    vector<int> nums{1,2,2,3,1};
    cout << findShortestSubArray(nums) << endl;
    return 0;
}
