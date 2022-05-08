#include "../include/include.h"

// 经典的爬梯子问题
// 动态规划 or 递归
int Solution(int n)
{ 
    vector<int> vec(n);
    vec[0] = 1;
    vec[1] = 2;
    for (int i = 2; i < n; ++i)
    {
        vec[i] = vec[i-1] + vec[i-2];
    }
    return vec[n-1];
}

int Solution2(int n)
{
    // 递归有大量重复计算, 所以要带上记忆数组, 固定写法
    vector<int> memo(n);
    return helper(n, memo);
}
int helper(int n, vector<int>& memo)
{
    if (n <= 1) return 1;
    if (memo > 0) return memo[n];
    return memo[n] = helper(n-1, memo) + helper(n-2, memo);
}

int main()
{
    assert_equal<int>(Solution(3), 3);
    return 0;
}
