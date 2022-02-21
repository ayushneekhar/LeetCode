#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int pre = 1;
        int suf = 1;
        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> answer(n);
        
        for(int i = 0; i < n; ++i){
            pre *= nums[i];
            prefix[i] = pre;
        }
        
        for(int i = n-1; i >= 0; --i){
            suf *= nums[i];
            suffix[i] = suf;
        }
        
        answer[0] = suffix[1];
        answer[n-1] = prefix[n-2];
        
        for(int i = 1; i < n-1; ++i){
            answer[i] = prefix[i-1] * suffix[i+1];
        }
        
        return answer;
    }
};
