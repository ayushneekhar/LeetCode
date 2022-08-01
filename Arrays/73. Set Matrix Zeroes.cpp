#include <bits/stdc++.h>
using namespace std;

// Using the 1st ROW as flag for every column if it should be 0d or not, if the 1st row's value is 0 that column
// will be 0'd out
// Since, we've already used index [0][0] as flag for column 0, we need to create a seperate flag to store if
// we need to 0 out ROW 0 or not.

// When 0ing out the rows and column we skip the 1st rows and column as we're using those to store if the row
// or column need to be 0d out or not, if we were to zero out the 1st rows and column we'd always get a 0 matrix
// So, we zero out every other element, then we check is the 1st column can be 0d out or not by the falg at index [0][0]
// And follwing this we check if the 1st row can be 0d out or not using the rowZero flag, we do it in this order because
// if we werre to do it in reverse we'd ero out the falg to check is column 1 needed to be 0d out or not, this would again
// lead to wrong answers as we altered the value of out flag before being able to use it.

// This method of setting the 1st index of rows and column to 0s works because we never iterate over 1st row elemetns or the
// 1st column elements more than once. hence they may be used as flags as tey wont affect out overall outcome.

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rowZero = 1;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    if (i == 0)
                        rowZero = 0;
                    else
                        matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); ++i)
        {
            for (int j = 1; j < matrix[0].size(); ++j)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int i = 0; i < matrix.size(); ++i)
                matrix[i][0] = 0;
        }

        if (!rowZero)
        {
            for (int i = 0; i < matrix[0].size(); ++i)
                matrix[0][i] = 0;
        }
    }
};