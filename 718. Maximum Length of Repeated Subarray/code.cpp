// Tabulation, saving the length of the prefix substring and greedly saving the max length, 
// comparing the values of current and last value and if same, increase the length by one. 
// Dynamic Programming  
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        int ans = 0;

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){ 
                dp[i][j] = A[i-1] == B[j-1] ? dp[i-1][j-1] + 1 : 0;
                ans = max(ans, dp[i][j]);
            }       
        }

        return ans;
    }
};