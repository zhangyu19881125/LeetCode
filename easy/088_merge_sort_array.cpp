#include "../include/include.h"

vector<int> Solution(const vector<int>& l, const vector<int>& r)
{
    vector<int> res;
    size_t i = 0, j = 0, k = 0;
    while (i < l.size() && j < r.size())
    {
        res[k++] = (l[i] < r[j]) ? l[i++] : r[j++];
    }
    return res;
}

// 题目要求把另一个合入另一个数组, 并不是新构造数组
void Solution(vector<int>& l, vector<int>& r)
{
    // 从后往前遍历
    l.reserve(l.size() + r.size());
    size_t i = l.size() - 1, j = r.size() - 1;
    while (i >= 0 && j >= 0)
    {
        l[i + j + 1] = (l[i] < r[j]) ? l[i--] : r[j--];
    }
    while (j >= 0) l[k--] = r[j--];
}
