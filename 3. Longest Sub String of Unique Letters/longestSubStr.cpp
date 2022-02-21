#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int usingBruteForce(string s)
    {
        int left = 0;
        int right = 0;

        int result = 0;

        map<char, int> alphabets;

        for (; right < s.length(); ++right)
        {
            alphabets[s[right]]++;
            while (alphabets[s[right]] > 1)
            {
                alphabets[s[left]]--;
                left++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }

    int usingSlidingWindow(string s)
    {
        int left = 0;
        int right = 0;

        int result = 0;

        unordered_map<char, int> alphabets;

        for (; right < s.length(); ++right)
        {
            alphabets[s[right]]++;
            while (alphabets[s[right]] > 1)
            {
                alphabets[s[left]]--;
                left++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};

int main()
{
    string str = "ayushneekhar";

    Solution s;
    cout << s.usingBruteForce(str) << endl;
    cout << s.usingSlidingWindow(str);
}