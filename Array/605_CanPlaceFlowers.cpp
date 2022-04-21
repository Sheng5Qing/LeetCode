/*种花问题*/
/*假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。
可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
给你一个整数数组??flowerbed 表示花坛，
由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。
另有一个数?n ，能否在不打破种植规则的情况下种入n朵花？
能则返回 true ，不能则返回 false。
*/
#include <iostream>
#include <vector>

using namespace std;

//暴力解,直接贪心做
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