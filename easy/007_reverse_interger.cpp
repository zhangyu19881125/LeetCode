#include "../include/include.h"

// 主要需要考虑溢出问题
int reverse(int x)
{
    int res = 0;
    while (x != 0)
    {
        if (abs(x) > INT_MAX / 10) return 0;
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    assert_equal<int>(reverse(123), 321);
    assert_equal<int>(reverse(-123), -321);
    assert_equal<int>(reverse(120), 21);
    return 0;
}
