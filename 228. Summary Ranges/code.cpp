#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() < 1) return {};
        
        string first = to_string(nums[0]);
        string last = to_string(nums[0]);
        vector<string> res;
                
        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums[i] != nums[i+1] - 1){
                if(first == last) res.push_back(first);
                else res.push_back(first + "->" + last);
                
                first = to_string(nums[i+1]);
            }
            last = to_string(nums[i+1]);
        }
        
        if(first == last) res.push_back(first);
        else res.push_back(first + "->" + last);
        
        return res;
    }
};