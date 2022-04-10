class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1;
        int miss = NULL;
        int i = 0;
        
        while(i < arr.size() && k != 0){
            if(arr[i] == num){
                i++;
                num++;
            } else {
                miss = num++;
                k--;
            }
        }
        
        return k != 0 ? num += k - 1 : miss;
    }
};