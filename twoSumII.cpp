#include <bits/stdc++.h>

using namespace std;

class Solutions
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (right > left)
        {
            if (nums[left] + nums[right] == target)
                return {left + 1, right + 1};
            if (nums[left] + nums[right] > target)
                right--;
            else
                left++;
        }
        return {left + 1, right + 1};
    }
};

int main()
{
    vector<int> bruh = {2, 3, 4};
    Solutions s;
    bruh = s.twoSum(bruh, 6);
    for (auto it : bruh)
        cout << it << " ";
}