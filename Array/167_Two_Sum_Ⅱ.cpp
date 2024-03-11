/*两数之和，输入有序数组*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size() - 1;
    while (l < r) {
        if(numbers[l] + numbers[r] == target){
            break;
        }else if (numbers[l] + numbers[r] > target) {
            --r;
        }else {
            ++l;
        }
    }
    return vector<int>{l + 1, r + 1};
}

int main(){
    return 0;
}