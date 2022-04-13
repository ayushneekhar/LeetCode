// Store the frequency of elements in one array in a map
// iterate over the second array and push the element if the frequency in the map is more than 0
// this ensures that only the minimum number of common elements are pushed.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> ans;
        
        for(auto it : nums1)
            m[it]++;
        
        for(auto it : nums2){
            if(m[it]){
                ans.push_back(it);
                m[it]--;
            }
        }
        
        return ans;
    }
};