#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    //     int minimumDeviation(vector<int>& nums) {
    //         int mean = 0;
    //         for(auto it: nums){
    //             mean += it;
    //         }

    //         mean = mean/nums.size();

    //         cout << "Mean: " << mean << endl;

    //         for(int i  = 0;  i < nums.size(); ++i){
    //             if(nums[i] % 2 == 0){
    //                 while(nums[i] > mean){
    //                     cout << "/2 ";
    //                     nums[i] = nums[i]/2;
    //                     cout << nums[i] << "\t";
    //                 }
    //             }
    //             else if(nums[i] % 2 == 1 && nums[i] < mean){
    //                 while(nums[i] < mean){
    //                     cout << "x2 ";
    //                     nums[i] = nums[i]*2;
    //                     cout << nums[i] << "\t";
    //                 }
    //             }
    //         }

    //         cout << endl;

    //         for(auto it: nums)
    //             cout << it << " ";

    //         return (*max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end()));
    //     }

    int minimumDeviation(vector<int> &nums)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] % 2 == 0)
                s.insert(nums[i]);
            else
                s.insert(nums[i] * 2);
        }

        int diff = *s.rbegin() - *s.begin();

        while (*s.rbegin() % 2 == 0)
        {
            int x = *s.rbegin();
            s.erase(x);
            s.insert(x / 2);

            diff = min(diff, *s.rbegin() - *s.begin());
        }

        return diff;
    }
};