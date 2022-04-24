// 之字形转换字符串
// 找规律, 找到坐标转换关系, 从前到后打印出来
// 0     6       12       18
// 1   5 7    11 13    17 19
// 2 4   8 10    14 16
// 3     9       15

#include "../include/include.h"

string Convert(string s, int rows)
{
    if (rows <= 1) return s;
    string res;
    int size = rows * 2 - 2;  // 分段长度, 第一行和最后一行少两个, 所以减2
    int n = s.size();
    for (int i = 0; i < rows; ++i)
    {
        for (int j = i; j < n; j += size)
        {
            res += s[j];
            int pos = j + size - i * 2;
            // if (不是第一行且不是最后一行) res += s[pos];
        }
    }
    return res;
}

int main()
{
    assert(Convert("PAYPALISHIRING", 3) == string("PAHNAPLSIIGYIR"));
    assert(Convert("PAYPALISHIRING", 4) == string("PINALSIGYAHRPI"));
    return 0;
}
