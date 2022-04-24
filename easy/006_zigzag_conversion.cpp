// 之字形转换字符串
// 找规律, 找到坐标转换关系, 从前到后打印出来
// 0     6       12       18
// 1   5 7    11 13    17 19
// 2 4   8 10    14 16
// 3     9       15
// 首先给字符串分段, 每段长度是 2*nRow - 2
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
            res += s[j];  // 直接按行扫描
            int pos = j + size - i * 2;  // 中间字符在原字符串中的位置
            if (i != 0 && i != rows - 1 && pos < n) res += s[pos];  // 不是首尾两行再加上中间的字符
        }
    }
    return res;
}

int main()
{
    assert_equal<string>(Convert("PAYPALISHIRING", 3), string("PAHNAPLSIIGYIR"));
    assert_equal<string>(Convert("PAYPALISHIRING", 4), string("PINALSIGYAHRPI"));
    return 0;
}
