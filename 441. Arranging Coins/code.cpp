// n(n+1)/2 = sum of n terms
// if su of n terms > total number of coins that means we reduce
// else we increase

class Solution {
public:
    int arrangeCoins(int n) {
        long left = 0, right = n;
        long curr, mid;
        
        while(left <= right){
            mid = left + (right - left)/2;
            curr = mid*(mid+1)/2;
            
            if(curr == n) return (int)mid;
            
            if(n < curr) right = mid - 1;
            else left = mid + 1;
        }
        
        return (int)right;
    }

    // Brute force
    int arrangeCoins(int n) {
        int i = 1;
        int rows = 0;
        while(i <= n){
            n -= i;
            i++;
            rows++;
        }
        
        return rows;
    }
};