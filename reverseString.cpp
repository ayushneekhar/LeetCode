#include <bits/stdc++.h>

using namespace std;
class Solutions
{
public:
    void reverseString(vector<char> &s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (right > left)
        {
            swap(s[right--], s[left++]);
        }
    }
};

int main()
{
    vector<char> bruh = {'h', 'e', 'l', 'l', 'o'};
    Solutions s;
    s.reverseString(bruh);
}