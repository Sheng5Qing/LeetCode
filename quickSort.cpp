#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &nums, int low, int high) {
    int pivot = nums[low];
    int i = low, j = high;
    while (i < j) {
        // 不加i< j， 可能会产生越界
        while (i< j && nums[j] > pivot) {   //从右往左开始找一个比pivot小的数
            j--;
        }
        if (i < j) {
            swap(nums[i++],nums[j]);    //把这个数放在基准值左边，同时右指针左移
        }
        while (i < j && nums[i] < pivot) {    //从左往右找一个比pivot大的数
            i++;
        }
        if (i < j) {
            swap(nums[i],nums[j--]);
        }
    }
    return i;   //最终划分完之后基准值位置
}

void quickSort(vector<int> &nums, int low, int high) {
    int mid;
    if (low < high) {
        mid = partition(nums,low,high); //划分
        quickSort(nums,low,mid-1);  //对左边进行快排
        quickSort(nums,mid+1,high); //对右边进行快排
    }
}

struct example {
    vector<int> nums;
};

int main(){
    //测试样例
    vector<example> e = {
        {{3, 2, 1, 4, 5}},
        {{4,8,5,3,9,1,7,6,2}},
        {{9,6,8,3,1,2,5,7,4}},
    };
    for (int i = 0; i < e.size(); i++) {
        quickSort(e[i].nums, 0, e[i].nums.size() - 1);
        for (int n: e[i].nums) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}