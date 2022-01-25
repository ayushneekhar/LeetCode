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
};

int main()
{
    Solutions s;
    vector<int> input = {4, 2, 0, 1, 3};
    vector<int> bruh = s.usingLinearPass(input);

    for (auto it : bruh)
        cout << it << " ";
}