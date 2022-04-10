#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> dups;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == nums[i - 1])
                dups.push_back(nums[i++]);
        }
        
        return dups;
    }
};