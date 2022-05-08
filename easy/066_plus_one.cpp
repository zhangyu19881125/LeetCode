#include "../include/include.h"

vector<int> Solution(vector<int> input)
{
    // 从后往前遍历, 用一个数字记录进位, 如果最前面需要进位, 直接在最前面插入1
    vector<int> res;
    size_t n = input.size();
    input[n-1]++;
    int carrage = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        int num = input[i] + carrage;
        input[i] = num % 10;
        carrage = num / 10;
        if (carrage == 0) break;  // 提前退出
    }
    if (carrage > 0) res.push_back(1);
    for (auto it : input)
    {
        res.push_back(it);
    }
    return res;
}

int main()
{
    vector<int> input({9, 9, 9});
    vector<int> output = Solution(input);
    for (auto it : output) cout << it;
    return 0;
}
