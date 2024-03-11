/*1比特和2比特字符*/
/*有两种特殊字符：
第一种字符可以用一比特 0 表示
第二种字符可以用两比特（10 或 11）表示
给你一个以 0 结尾的二进制数组 bits ，如果最后一个字符必须是一个一比特字符，则返回 true 。
*/
#include <iostream>
#include <vector>

using namespace std;

//简单跳格子，时间复杂度O(n)，击败100%
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