#include "../include/include.h"

// 这道题很简单, 但我不明白为啥解答搞那么复杂, 直接从后往前遍历不行吗?
size_t Solution(const string& s)
{
    if (s.length() == 0) return 0;
    size_t res = 0, n = s.length(), i = n - 1;
    while (i >= 0 && s[i] == ' ') --i;
    if (i < 0) return 0;
    while (i >= 0 && s[i] != ' ')
    {
        ++res;
        --i;
    }
    return res;
}

int main()
{
    assert_equal<size_t>(Solution("hello world"), 5);
    return 0;
}
