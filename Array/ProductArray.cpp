/*剑指offer 66.构造乘积数组*/
/*给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
其中?B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 
即?B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    //超时了？？？复杂度O(n^2)，怪不得
    vector<int> constructArr3(vector<int>& a) {
        vector<int> b;
        int ci = 0,cj = 0;
        for(auto c:a){
            int product = 1;
            for(auto i:a){
                if(ci != cj){
                    product *= i;
                }
                cj++;
            }
            ci++;
            cj = 0;
            b.push_back(product);
        }
        return b;
    }

    //过了，时间复杂度O(n),
    vector<int> constructArr2(vector<int>& a) {
        const unsigned length = a.size();
        //L为i左侧所有元素的乘积
        vector<int> L(length,0);
        L[0] = 1;
        for(int i = 1; i != length; ++i){
            L[i] = a[i - 1] * L[i - 1];
        }
        //R为i右侧所有元素乘积,同理
        vector<int> R(length,0);
        R[length - 1] = 1;
        for(int i = length - 2; i != -1; --i){
            R[i] = a[i + 1] * R[i + 1];
        }
        //构建输出vector
        vector<int> answer;//一定要初始化长度，否则无法使用下标访问
        //int* answer  = new int[length];
        for(int i = 0; i != length; ++i){
            answer.push_back(L[i] * R[i]);
        }
        return answer;
    }
    
    //简化一下写法
    vector<int> constructArr(vector<int>& a){
        const unsigned length = a.size();
        int temp = 1;
        vector<int> answer(length);
        for(int i = 0; i < length; temp *= a[i], ++i){
            answer[i] = temp;
        }
        //重置temp,进行后缀遍历
        temp = 1;
        for(int i = length - 1; i >= 0; temp *= a[i], --i){
            answer[i] *= temp;
        }
        return answer;
    }
};

int main(){
    Solution s;
    vector<int> a = {1,2,0,4,0};
    for(auto c:s.constructArr2(a)){
       cout << c << " ";
    }

    return 0;
}