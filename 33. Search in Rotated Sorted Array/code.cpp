// While binary searching for the pivot, check if the elemnt we're looking for occurs, if not search lol

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(nums[0] == target) return 0;
            else return -1;
        }
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(right > left){
            int mid = left + (right - left) / 2;
            
            if(nums[right] == target) return right;
            if(nums[left] == target) return left;
            
            if(nums[right] < mid) right--;
            else left++;
        }
        
        return -1;
    }

    // Better O(log n) solution
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(right >= left){
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target) return mid;
            
            if(nums[right] <= nums[mid])
                if(target < nums[mid] && target >= nums[left]) right = mid - 1;
                else left = mid + 1;
            else 
                if(nums[right] >= target && target > nums[mid]) left = mid + 1;
                else right = mid - 1;
        }
        
        return -1;
    }
};