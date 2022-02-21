#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int size = nums.size();

        for (int i = 1; i < size; ++i)
            nums[i] = nums[i] + nums[i - 1];

        nums.insert(nums.begin(), 0);
        nums.insert(nums.end(), 0);

        for (int i = 1; i < size + 1; ++i)
            if (nums[i - 1] == (nums[size] - nums[i]))
                return i - 1;

        return -1;
    }
};