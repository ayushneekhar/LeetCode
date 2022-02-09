#include <bits/stdc++.h>

using namespace std;

class Solutions
{
public:
    vector<int> usingLinearPass(vector<int> &nums)
    {
        for (auto it = nums.begin(); it != nums.end(); ++it)
            *it = pow(*it, 2);
        sort(nums.begin(), nums.end());
        return nums;
    }

    vector<int> usingTwoPointer(vector<int> &nums)
    {
        int n = nums.size() - 1;
        vector<int> result(n + 1);
        int right = n;
        int left = 0;

        while (right >= left)
        {
            if (abs(nums[right]) >= abs(nums[left]))
            {
                result[n--] = pow(nums[right--], 2);
            }
            else if (abs(nums[right]) <= abs(nums[left]))
            {
                result[n--] = pow(nums[left++], 2);
            }
        }
        return result;
    }
};

int main()
{
    Solutions s;
    vector<int> input = {4, 2, 0, 1, 3};
    vector<int> bruh = s.usingLinearPass(input);

    for (auto it : bruh)
        cout << it << " ";
}