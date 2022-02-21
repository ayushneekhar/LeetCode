#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
            return 1;

        sort(intervals.begin(), intervals.end());

        int ans = intervals.size();

        int rightEle = intervals[0][1];
        int leftEle = intervals[0][0];

        for (int i = 1; i < intervals.size(); ++i)
        {
            if (rightEle >= intervals[i][1] && leftEle < intervals[i][0])
            {
                ans--;
            }
            else if (leftEle == intervals[i][0])
            {
                ans--;
                rightEle = max(intervals[i][1], rightEle);
            }
            else
            {
                leftEle = intervals[i][0];
                rightEle = intervals[i][1];
            }
        }

        return ans;
    }
};