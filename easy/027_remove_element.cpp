#include "../include/include.h"

int RemoveElement(vector<int>& nums, int val)
{
    int res = 0;
    // 相等则跳过, 不等则覆盖
    for (int i = 0; i < nums.size(); ++i)
    {
        if (val != nums[i]) nums[res++] = nums[i];
    }
    return res;
}

int main()
{
    vector<int> nums({3, 2, 2, 3});
    assert_equal<int>(RemoveElement(nums, 3), 2);
    return 0;
}
