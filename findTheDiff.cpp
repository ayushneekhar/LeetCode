#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        if (s.length() < 1)
            return t[0];

        sort(t.begin(), t.end());
        sort(s.begin(), s.end());

        for (int i = 0; i < t.length(); ++i)
        {
            if (s[i] != t[i])
                return t[i];
        }
        return t[0];
    }
};