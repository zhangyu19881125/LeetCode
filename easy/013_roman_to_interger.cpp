#include "../include/include.h"

int romeToInt(string s)
{
    int res = 0;
    unordered_map<char, int>m({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}});
    // 从前往后读入字符, 如果字符是最后一个, 或者比后面的字符大, 则加上, 否则减去
    size_t n = s.size();
    for (size_t i = 0; i < n; ++i)
    {
        int num = m[s[i]];
        if (i == n - 1 || (num >= m[s[i+1]])) res += num;
        else res -= num;
    }
    // 不考虑溢出的情况
    return res;
}

int main()
{
    assert_equal<int>(romeToInt("III"), 3);
    assert_equal<int>(romeToInt("IV"), 4);
    assert_equal<int>(romeToInt("IX"), 9);
    assert_equal<int>(romeToInt("LVIII"), 58);
    assert_equal<int>(romeToInt("MCMXCIV"), 1994);
}
