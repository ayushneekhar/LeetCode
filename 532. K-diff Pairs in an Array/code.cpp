#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_map<int, int> imap;
        int count = 0;

        for (auto it : nums)
            imap[it]++;

        for (auto i = imap.begin(); i != imap.end(); ++i)
        {
            int target = k + i->first;
            if (k == 0)
            {
                if (i->second > 1)
                    count++;
            }
            else if (imap.find(target) != imap.end())
            {
                count++;
            }
        }

        return count;
    }
};