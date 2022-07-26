#include <bits/stdc++.h>
using namespace std;

// Trick: Fibonacci sequence type Dynamic programming
// Logic: the max profit to be made from robbing house i can be determined by:
// 1. If we decide to rob house i, we cant rob house i - 1, therefore total profit = money at i + max profit upto at i - 2
// 2. If we decide not to rob house i, we the max profit = max profit upto i - 1
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int rob1 = nums[0];
        int rob2 = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i)
        {
            int tmp = rob2;
            rob2 = max(rob1 + nums[i], rob2);
            rob1 = tmp;
        }

        return max(rob1, rob2);
    }
};