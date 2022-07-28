#include <bits/stdc++.h>
using namespace std;

// Trick: the trick in this quesiton is to treat 2 numbers as a single unit to implement DP
// i.e. say we have a number 226, till index 0, 2 can only be decoded in 1 way, B, till index 1, the string can be decoded
// in 2 ways, : {2, 2} or {22}, these are ut fixed base cases for all the further subprobelms.
// Now, at index 3 we have a substring 226, say we decide to pair 2 and 6 togeter, lets assume 26 to be X 2{26}, then our new
// Substring is 2X, 2X can be decoded in number of ways that the substring preceeding 26 (X) may be decoded, i.e. 1
// If we assume to take 2 and 6 seperately, 22{6} can be decoded in the same amount of ways 22 can be decoded, i.e. 2,
// therefore, the total number of ways we may decode 226 will be the sum of:
// Number of ways to decode 22 + number of ways to decode 2 = 2 + 1 = 3.

// NOTE: Why arent we adding +1 if we decode a string?
// We dont add +1 because the total number of ways 2 number may be decoded are fiex, i.e either taking single digit
//  or taking the double digit combined, these we have already handled as the base cases at dp[0] and dp[1]

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        if (s.length() == 1)
            return 1;

        vector<int> dp(s.length(), 0);
        dp[0] = 1;
        dp[1] = ((s[0] == '1' || (s[0] == '2' && s[1] < '7')) ? 1 : 0) + (s[1] != '0');

        for (int i = 2; i < s.length(); ++i)
        {
            if (s[i] == '0' && (s[i - 1] == '0' || s[i - 1] > '2'))
                return 0;
            dp[i] = s[i] != '0' ? dp[i - 1] : 0;
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
                dp[i] += dp[i - 2];
        }

        return dp[s.length() - 1];
    }
};