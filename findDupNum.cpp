#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums[0];

        unordered_map<int, int> imap;

        for (auto it : nums)
        {
            if (imap[it])
                return it;
            else
                imap[it]++;
        }
        return 0;
    }

    int usingSort(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
                return nums[i];
        }

        return 0;
    }
};