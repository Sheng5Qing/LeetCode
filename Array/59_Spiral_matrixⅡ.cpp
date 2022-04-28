#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //����vector��ά����
        vector<vector<int>> ret(n,vector<int>(n,0));
        //����x,y�������Լ�ƫ���� (x, y)->(x + dx, y + dy)
        int x = 0, y = 0; 
        // �ֱ�Ϊ���ң����£��������ϵ�ƫ����
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        //������������
        for(int i = 1, d = 0; i <= n*n; ++i){
            //��ֵ
            ret[x][y] = i;
            //����������һλ
            int a = x + dx[d];
            int b = y + dy[d];
            // ���ñ߽磬�����߽缴������
            if(a < 0 || a == n || b < 0 || b == n || ret[a][b]){
                d = (d + 1) % 4;
                //��ʱx��¼�µ���δԽ��ǰ��λ��
                a = x + dx[d];
                b = y + dy[d];
            }
            x = a;
            y = b;
        }
        return ret;
    }
};