/*1���غ�2�����ַ�*/
/*�����������ַ���
��һ���ַ�������һ���� 0 ��ʾ
�ڶ����ַ������������أ�10 �� 11����ʾ
����һ���� 0 ��β�Ķ��������� bits ��������һ���ַ�������һ��һ�����ַ����򷵻� true ��
*/
#include <iostream>
#include <vector>

using namespace std;

//�������ӣ�ʱ�临�Ӷ�O(n)������100%
bool isOneBitCharacter(vector<int>& bits) {
    const int len = bits.size();
    int pos = 0;
    while (pos < len - 1) {
        pos += (bits[pos] == 1 ? 2 : 1);
    }
    return pos == len - 1;
}

int main(){
    return 0;
}