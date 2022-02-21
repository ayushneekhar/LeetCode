#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int sum = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        int max_len = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i] == 0 ? -1 : 1;
            if (m.count(sum))
            {
                max_len = max(max_len, i - m[sum]);
            }
            else
            {
                m[sum] = i;
            }
        }
        return max_len;
    }
};