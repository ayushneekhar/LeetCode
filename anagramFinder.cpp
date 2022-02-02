#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> pvec(26, 0);
        vector<int> svec(26, 0);
        vector<int> index;

        if (s.size() < p.size())
            return index;

        for (int i = 0; i < p.size(); ++i)
        {
            ++pvec[p[i] - 'a'];
            ++svec[s[i] - 'a'];
        }

        if (pvec == svec)
            index.push_back(0);

        for (int i = p.size(); i < s.size(); ++i)
        {
            ++svec[s[i] - 'a'];
            --svec[s[i - p.size()] - 'a'];

            if (svec == pvec)
                index.push_back(i - p.size() + 1);
        }
        return index;
    }
};