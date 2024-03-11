#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //定义vector二维数组
        vector<vector<int>> ret(n,vector<int>(n,0));
        //设置x,y轴坐标以及偏移量 (x, y)->(x + dx, y + dy)
        int x = 0, y = 0; 
        // 分别为向右，向下，向左，向上的偏移量
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        //遍历整个数组
        for(int i = 1, d = 0; i <= n*n; ++i){
            //赋值
            ret[x][y] = i;
            //索引移向下一位
            int a = x + dx[d];
            int b = y + dy[d];
            // 设置边界，触碰边界即换方向
            if(a < 0 || a == n || b < 0 || b == n || ret[a][b]){
                d = (d + 1) % 4;
                //此时x记录下的是未越界前的位置
                a = x + dx[d];
                b = y + dy[d];
            }
            x = a;
            y = b;
        }
        return ret;
    }
};