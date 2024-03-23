//冒泡排序
#include<iostream>
#include<vector>

using namespace std;

void bubbleSort(vector<int> &nums) {
    for (int i = 0; i <nums.size(); i++) {
        for (int j = 0; j < nums.size() - i - 1; j++) {
            if (nums.at(j) > nums.at(j + 1)) {
                swap(nums.at(j), nums.at(j + 1));
            }
        }
    }
}

struct example {
    vector<int> nums;
};


int main() {
    vector<example> e = {
        {{3, 2, 1, 4, 5}},
        {{4,8,5,3,9,1,7,6,2}},
        {{1,1,20,34,1,1}},
    };
    for (int i = 0; i < e.size(); i++) {
        bubbleSort(e[i].nums);
        for (int n: e[i].nums) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}