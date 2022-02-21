#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int count = 0;
        for (int i = 2; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 2 - count])
            {
                cout << " nums[" << i << "]: " << nums[i] << " == "
                     << "nums[" << i - 2 - count << "]: " << nums[i - 2 - count] << "   ";
                ++count;
                cout << "New count: " << count << endl;
            }
            else
            {
                cout << "nums[" << i << "]: " << nums[i] << " != "
                     << "nums[" << i - 2 - count << "]: " << nums[i - 2 - count] << "   ";
                cout << " Not Equal, new array: ";
                nums[i - count] = nums[i];
                for (auto it : nums)
                    cout << it << " ";
                cout << endl;
            }
        }
        cout << endl;
        return nums.size() - count;
    }
};