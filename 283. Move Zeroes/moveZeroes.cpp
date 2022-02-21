#include <bits/stdc++.h>

using namespace std;
class Solutions
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int left = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[left++]);
            }
        }
    }
};

int main()
{
    vector<int> bruh = {0, 1, 0, 3, 12};
    Solutions s;
    s.moveZeroes(bruh);
}