
// Explaination

// CumSum[j] - CumSum[i] = K  // This is the condition that we want to be able to satisft.

// CumSum[j] = Cumilative sum at index j
// CumSum[i] = Cumilative sum at index i

// Array:       1    2    3   4    5     6    7     8     9
// CumSum:      1    3    6   10   15   21    28   36    45
//              --------------------------
// 			    -----------------_________
// 							     
// k = 11

// CumSum[5] (21) - CumSum[3] (10) = 11 = k // This case satisfies our condition

// Rearranging our condition we get: CumSum[j] - k = CumSum[i]

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp = {{0,1}};
        int count = 0, sum = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            count += mp[sum-k];
            mp[sum]++;
        }
        
        return count;
        
    }
};