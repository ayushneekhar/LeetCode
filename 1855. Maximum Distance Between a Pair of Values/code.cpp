// Check the condition for a valid pair first
// if the condition is satisfied updae the two pointers keeping in mind their position
// if nums2 pointer reaches the end, no point in updating the nums1 pointer as the distance will
// only ever decrease after that point

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int dist = 0;
        
        while(i < nums1.size() || j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                dist = max(dist, j - i);
                if(j < nums2.size() - 1) ++j;
                else break;
            } else if(i < j && i < nums1.size() - 1) ++i;
            else if(j < nums2.size() && j < nums2.size() - 1) ++j;
            else break;
        }
        
        // Same approch just made shorter by checking invalid set before valid set
        // Don't need to check j > i as j - i will be negative, which wont change the value in our case.
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] > nums2[j]) ++i;
            else dist = max(dist, j++ - i);
        }
        
        return dist;
    }
};