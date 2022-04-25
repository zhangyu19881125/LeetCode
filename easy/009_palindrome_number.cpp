#include "../include/include.h"

bool isPalindrome(int x)
{
    if (x < 0) return false;
    int res = 0;

    while (x / 10 > 0)
    {
        if (res == x || res == x / 10) return true;
        res = res * 10 + x % 10;
        x = x / 10;
    }
    return false;
}

int main()
{
    assert_equal<bool>(isPalindrome(121), true);
    assert_equal<bool>(isPalindrome(-121), false);
    assert_equal<bool>(isPalindrome(10), false);
}
