/*414.���������*/
/*����һ���ǿ����飬���ش������� ��������� ����������ڣ��򷵻���������������*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    //������
    //�ȴӴ�С�Ÿ���
    void quickSortGreater(int left, int right,vector<int> &arr){
        if(left >= right)
            return;
        if(left < 0 || right >= arr.size()){
            cout << "error" << endl;
            return;
        }
        int i, j, base, temp;
        i = left;
        j = right;
        //�������Ϊ��׼
        base = arr[left];
        while (i < j) {
            while (arr[j] <= base && i < j) {
                j--;
            }
            while (arr[i] >= base && i < j) {
                i++;
            }
            if(i < j){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }            
        }
        //��׼����λ
        arr[left] = arr[i];
        arr[i] = base;
        quickSortGreater(left, i - 1, arr);
        quickSortGreater(i + 1, right, arr);
    }
    int thirdMax(vector<int>& nums) {
        quickSortGreater(0, nums.size() - 1, nums);
        //sort(nums.begin(), nums.end(), greater<>());
        int i = 0,count = 1;
        if(nums.size() < 3){
            return nums[0];
        }else {
            while (i != nums.size() && count != 3) {
                if(nums[i] != nums[i + 1]){
                    i++;
                    count++;
                }else{
                    i++;
                }
            }
        }
        return nums[i];
    }
};

int main(){
    Solution s;
    vector<int> a ={2,3,2,1,4};
    // for(auto c:a){
    //     cout << c << " ";
    // }
    cout << s.thirdMax(a);

    return 0;
}   