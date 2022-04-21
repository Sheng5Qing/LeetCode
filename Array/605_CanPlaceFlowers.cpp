/*�ֻ�����*/
/*������һ���ܳ��Ļ�̳��һ���ֵؿ���ֲ�˻�����һ����ȴû�С�
���ǣ���������ֲ�����ڵĵؿ��ϣ����ǻ�����ˮԴ�����߶�����ȥ��
����һ����������??flowerbed ��ʾ��̳��
������ 0 �� 1 ��ɣ����� 0 ��ʾû��ֲ����1 ��ʾ��ֲ�˻���
����һ����?n ���ܷ��ڲ�������ֲ��������������n�仨��
���򷵻� true �������򷵻� false��
*/
#include <iostream>
#include <vector>

using namespace std;

//������,ֱ��̰����
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    unsigned i = 0;
    if(flowerbed.size() == 1){
        if(flowerbed[i] == 1)
            return n <= 0;
        else
            return --n <= 0;
    }
    while (i < flowerbed.size()) {
        if(flowerbed[i] == 0){
            if(i == flowerbed.size() - 1){
                if(flowerbed[i - 1] == 0){
                    n--;
                }
                break;
            }else if (flowerbed[i + 1] == 0) {
                n--;
                i +=2;
            }else {
                i += 3;
            }
        }else {
            i += 2;
        }
    }
    return n <= 0;
}

int main(){
    vector<int> v = {1,0,0,0,1,0,0};
    if (canPlaceFlowers(v,2)) {
        cout << "yes" << endl;
    }else {
        cout << "no" << endl;
    }
    return 0;
}