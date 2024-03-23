// 偏爱字符
// 输入
// 5 3
// A B C
// DAZEC
// 输出
// AAACC

#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m, r[N], l[N];
string s;
int state;

int main()
{
    int n, m;
    cin >> n >> m;
    string res(n, ' '); //结果数组，初始化为n个空格
    for(int i = 0; i < m; i++)
    {
        char ch;
        cin >> ch;
        state |= 1 << (ch - 'A');   //节省内存，状态压缩
    }
    cin >> s;
    r[n] = 1e9;
    l[0] = -1e9;
    for (int i = n - 1; i >= 0; i--)
    {
        int x = s[i] - 'A';
        if (state >> x & 1)
        {
            r[i] = i;
        }
        else
        {
            r[i] = r[i + 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int x = s[i] - 'A';
        if (state >> x & 1)
        {
            l[i] = i;
        }
        else if (i > 0)
        {
            l[i] = l[i - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        int left = i - l[i], right = r[i] - i;
        if (left <= right)
        {
            res[i] = s[l[i]];
        }
        else
        {
            res[i] = s[r[i]];
        }
    }
    cout << res << endl;
}