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

    char usingXOR(string s, string t)
    {
        char r = 0;
        for (char c : s)
        {
            cout << "t: " << r << "^" << c << " > " << (char)(r ^ c) << endl;
            r ^= c;
        }
        cout << "r = " << (char)r << endl;
        for (char c : t)
        {
            cout << "t: " << r << "^" << c << " > " << (char)(r ^ c) << endl;
            r ^= c;
        }
        cout << "r = " << (char)r << endl;
        return r;
    }

    char findTheDifference(string s, string t)
    {
        int ascii = 0;

        for (char it : t)
            ascii += (int)it;
        for (char it : s)
            ascii -= (int)it;

        return (char)ascii;
    }
};