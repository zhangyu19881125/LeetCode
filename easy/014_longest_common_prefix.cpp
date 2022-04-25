#include "../include/include.h"

string LongestCommonPrefix(vector<string> input)
{
    if (input.size() == 0) return "";
    if (input.size() == 1) return input[0];
    sort(input.begin(), input.end());
    // 排序之后只需要查找首尾两个字符串的公共前缀
    const string& l = input[0];
    const string& r = input.back();
    int i = 0;
    int len = min(l.size(), r.size());
    while (i < len && l[i] == r[i]) ++i;
    return l.substr(0, i);
}

int main()
{
    assert_equal<string>(LongestCommonPrefix({"flower", "flow", "flight"}), "fl");
    assert_equal<string>(LongestCommonPrefix({"dog", "racecar", "car"}), "");
}
