class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        multimap<int, int> mm;
        unordered_map<int, int> mp;
        
        for(auto it : nums){
            mp[it]++;
        }
        
        for(auto it : mp){
            mm.insert(pair<int, int>(it.second, it.first));
        }
        
        vector<int> v;
        auto iter = mm.rbegin();
        
        while(k != 0){
            v.push_back(iter->second);
            iter++;
            k--;
        }
        
        return v;
    }
};