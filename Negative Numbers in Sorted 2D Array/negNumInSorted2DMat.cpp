#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size() - 1;
        int n = grid[0].size() - 1;
        int count = 0;

        for (int i = m; i >= 0; --i)
        {
            if (gird[m][n] >= 0)
                break;
            for (int j = n; j >= 0; --j)
            {
                if (grid[i][j] >= 0)
                    break;
                cout << grid[i][j] << " ";
                count++;
            }
            cout << endl;
        }

        return count;
    }
};