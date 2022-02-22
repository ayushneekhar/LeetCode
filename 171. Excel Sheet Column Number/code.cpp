#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int titleToNumber(string columnTitle) // First try
    {
        unordered_map<char, int> alph;
        int j = 1;
        for (char i = 'A'; i <= 'Z'; ++i)
        {
            alph[i] = j;
            j++;
        }

        int column = 0;

        for (int i = 0; i < columnTitle.length(); ++i)
        {
            column += pow(26, columnTitle.length() - i - 1) * alph[columnTitle[i]];
        }
        cout << endl;
        return column;
    }

    int titleToNumber(string columnTitle) // Optimized first try by not using map and calulating alphabet pos directly; 0ms
    {
        int column = 0;

        for (int i = 0; i < columnTitle.length(); ++i)
        {
            column += pow(26, columnTitle.length() - i - 1) * (columnTitle[i] - 64);
        }
        return column;
    }
};