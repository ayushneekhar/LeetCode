#include <bits/stdc++.h>
using namespace std;

// Trick: same as coin change problem
// Here we solve the sub problem say, to get to the number 12 we can go down 3 paths in reverse:
// Either start with 1*1 or 2*2 or 3*3 (*4 > 12 so doesnt work)
// For every path we now have new sub problems, say we go down path 1*1, then instead of finding number of perfect squares
// for the number 12, we need to find for number 12 - 1*1 = 11, or if we went down path 2*2, we would have to find the number
// of perfect squares to get to the number 12 - 2*2 = 8
// Since we're finding the number of perfect squares to get to number i starting form 1, we already have all the subproblems
// already figured out.

// So for 12 we go down: 11, 8, 3, then for 8 we go down: 7, 4, then for 4 we go down 3, 0, ) is the answer.
// but we start from the beginnign, to get to 0, we need 0

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, n);
        dp[0] = 0;

        for (int target = 1; target < n + 1; ++target)
        {
            for (int j = 1; j * j < target + 1; ++j)
            {
                dp[target] = min(dp[target], 1 + dp[target - j * j]);
            }
        }

        return dp[n];
    }
};