#include <bits/stdc++.h>
using namespace std;

// Trick: the trick in this question is to split this question into 2 parts:
// Part - 1: Taking the case where we rob the 1st house, if we do this, we may not rob the last house.
// Part - 2: Taking the case where we rob the 2nd house, if we do this, we may rob the last house.
// Visually:
// 1 2 3 4 can be split into: (max_rob[1 2 3] 4) & (1 max_rob[2 3 4]), here we find the max we may rob given we rob house 1
// and the max we may rob given we skip house 1 and.

class Solution
{
    int helper(vector<int> &nums, int start, int end)
    {
        int rob1 = nums[start];
        int rob2 = max(rob1, nums[start + 1]);

        for (int i = start + 2; i < end; ++i)
        {
            int tmp = rob2;
            rob2 = max(nums[i] + rob1, rob2);
            rob1 = tmp;
        }

        return max(rob1, rob2);
    }

public:
    int rob(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return *max_element(nums.begin(), nums.end());

        // Return the maximum we may rob of the 2 cases.
        return max(helper(nums, 0, nums.size() - 1), helper(nums, 1, nums.size()));
    }
};