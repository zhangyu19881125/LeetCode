#include "../include/include.h"

bool CheckSame(const string& input, size_t i, const string& substr)
{
    for (size_t j = 0; j < substr.size(); ++j)
    {
        if (input[i + j] != substr[j]) return false;
    }
    return true;
}

size_t StrStr(const string& input, const string& substr)
{
    if (input.empty() || substr.empty()) return 0;

    size_t m = input.size(), n = substr.size();
    for (size_t i = 0; i < m - n; ++i)
    {
        if (input[i] == substr[0] && CheckSame(input, i, substr)) return i;
    }
    return -1;
}

int main()
{
    assert_equal<size_t>(StrStr("hello", "ll"), 2);
    return 0;
}
