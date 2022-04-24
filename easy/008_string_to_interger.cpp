#include "../include/include.h"

int myAtoi(string str)
{
    if (str.empty()) return 0;
    int sign = 1, base = 0, i = 0, n = str.size();
    while (i < n && str[i] == ' ') ++i;  // 跳过空格
    
    // 判断符号
    if (i < n && (str[i] == '+' || str[i] == '-'))
    {
        sign = (str[i++] == '+') ? 1 : -1;
    }

    // 从前往后读数字
    while (i < n && str[i] >= '0' && str[i] <= '9')
    {
        // 考虑溢出
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7))
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        base = base * 10 + (str[i++] - '0');
    }
    return base * sign;
}

int main()
{
    assert_equal<int>(myAtoi("42"), 42);
    assert_equal<int>(myAtoi("    -42"), -42);
    assert_equal<int>(myAtoi("123 with words"), 123);
    assert_equal<int>(myAtoi("words and 123"), 0);
    assert_equal<int>(myAtoi("-91283472332"), -2147483648);
    return 0;
}
