/*��ָoffer 66.����˻�����*/
/*����һ������ A[0,1,��,n-1]���빹��һ������ B[0,1,��,n-1]��
����?B[i] ��ֵ������ A �г����±� i �����Ԫ�صĻ�, 
��?B[i]=A[0]��A[1]������A[i-1]��A[i+1]������A[n-1]������ʹ�ó�����
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    //��ʱ�ˣ��������Ӷ�O(n^2)���ֲ���
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

    //���ˣ�ʱ�临�Ӷ�O(n),
    vector<int> constructArr2(vector<int>& a) {
        const unsigned length = a.size();
        //LΪi�������Ԫ�صĳ˻�
        vector<int> L(length,0);
        L[0] = 1;
        for(int i = 1; i != length; ++i){
            L[i] = a[i - 1] * L[i - 1];
        }
        //RΪi�Ҳ�����Ԫ�س˻�,ͬ��
        vector<int> R(length,0);
        R[length - 1] = 1;
        for(int i = length - 2; i != -1; --i){
            R[i] = a[i + 1] * R[i + 1];
        }
        //�������vector
        vector<int> answer;//һ��Ҫ��ʼ�����ȣ������޷�ʹ���±����
        //int* answer  = new int[length];
        for(int i = 0; i != length; ++i){
            answer.push_back(L[i] * R[i]);
        }
        return answer;
    }
    
    //��һ��д��
    vector<int> constructArr(vector<int>& a){
        const unsigned length = a.size();
        int temp = 1;
        vector<int> answer(length);
        for(int i = 0; i < length; temp *= a[i], ++i){
            answer[i] = temp;
        }
        //����temp,���к�׺����
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