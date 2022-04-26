#include "../include/include.h"

size_t RemoveDuplicate(vector<int>& nums)
{
    // 1 1 2 3 3 3 3 4 5 5 5 6
    size_t l = 0, r = 0, n = nums.size();
    while (r < n)
    {
        if (nums[l] == nums[r]) ++r;
        else nums[++l] = nums[r++];
    }
    return nums.empty() ? 0 : l + 1;
}

int main()
{
    vector<int> nums({1, 1, 2, 3, 3, 3, 4, 5, 5, 6});
    assert_equal<size_t>(RemoveDuplicate(nums), 6);
    return 0;
}
