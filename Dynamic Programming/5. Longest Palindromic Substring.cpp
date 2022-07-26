#include <bits/stdc++.h>
using namespace std;

// Trick: to calculate a palindrome we can start scanning from the centre outwards, i.e bacab,
// c == c, a == a, b == b, incrementing left each time.

// Where is the Dynamic Programming?
// As we scan outwards our length grows, therefore, say at length 3 our string is "aca", in normal case we would need to
// check every cahracter to verify if this is a palindrome or not, which would take O(n) amount of n = length of substring
// however, in our case since we only increase our length if the current length substring is a
// plaindrome we can check if the new increased length substring is a plaindrome or not in O(1) time by just comparing
// the outermost alphabets since we know that all the substring of length lesser in bettween our left and right limits is
// definitly as palindrome as we've already caheck it before increaseing out length.

// Why have 2 cases?
// We have to cases to handle the even adn odd length palindromes seperately.
// "abcba" and "abba" these 2 cases.

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int resLen = 0;    // Save the length of the longest palindromic substring
        int res_start = 0; // The index from where out substring starts

        for (int i = 0; i < s.length(); ++i)
        {
            // Odd length substrings, i.e, one center character and palindrome around it
            int left = i, right = i; // taking the ith character as the centre and checking outwards.

            while (left >= 0 && right < s.length() && s[left] == s[right]) // Only continue if a plaindrome condition is satisfied
            {
                if (right - left + 1 > resLen) // If the length of this new palindrome is more than anything we've
                                               // encountered before, ever, then update the length and starting index.
                {
                    resLen = right - left + 1;
                    res_start = left;
                }
                left--;
                right++;
            }

            // Even length substring, i.e, center has 2 repeating character and no odd no. of characters
            // repeat above but this time start from 2 adjscent characters rather than the same character
            left = i, right = i + 1;

            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                if (right - left + 1 > resLen)
                {
                    resLen = right - left + 1;
                    res_start = left;
                }
                left--;
                right++;
            }
        }

        // return the longest palindrome starting from res_start index of length resLen
        return s.substr(res_start, resLen);
    }
};